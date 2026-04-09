/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 09:15:13 by almaldon          #+#    #+#             */
/*   Updated: 2025/08/19 10:49:31 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static int	**create_pipes(int count)
{
	int	**pipes;
	int	i;

	pipes = malloc(sizeof(int *) * (count - 1));
	if (!pipes)
		return (NULL);
	i = 0;
	while (i < count - 1)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
			return (ft_free_pipes(pipes, count), NULL);
		if (pipe(pipes[i]) < 0)
		{
			perror("pipe");
			return (ft_free_pipes(pipes, count), NULL);
		}
		i++;
	}
	return (pipes);
}

static void	exec_command_or_builtin(t_command *cmd, t_env *st_env,
	t_pipeline *pl, int **pipes)
{
	char		*cmd_path;
	t_builtin	b;

	cmd_path = find_command_path(cmd->argv[0]);
	if (cmd_path)
	{
		execve(cmd_path, cmd->argv, st_env->env);
		g_exit_status = 2;
		perror("execve");
		exit(1);
	}
	b = identify_builtin(cmd->argv[0]);
	if (b != BUILTIN_NONE)
	{
		run_builtin(cmd, st_env->env_matrix, st_env->env_3);
		exit(0);
	}
	write(2, cmd->argv[0], ft_strlen(cmd->argv[0]));
	write(2, ": command not found\n", 21);
	free_pipeline(pl);
	ft_free_stuff("m3", st_env->env, st_env->env_3);
	free(pl->pids);
	ft_free_pipes(pipes, pl->count - 1);
	g_exit_status = 127;
	exit(127);
}

static void	fork_aux(t_pipeline *pl, t_env *st_env)
{
	free_pipeline(pl);
	ft_free_stuff("m33", st_env->env, st_env->env_matrix, st_env->env_3);
	free(pl->pids);
}

static void	fork_commands(t_pipeline *pl, int **pipes, t_env *st_env)
{
	int	i;

	i = -1;
	while (++i < pl->count)
	{
		pl->pids[i] = fork();
		if (pl->pids[i] < 0)
			perror("fork");
		if (pl->pids[i] == 0)
		{
			if (i > 0)
				dup2(pipes[i - 1][0], STDIN_FILENO);
			if (i < pl->count - 1)
				dup2(pipes[i][1], STDOUT_FILENO);
			close_all_pipes(pipes, pl->count);
			if (apply_redirections(&pl->cmds[i]) < 0)
			{
				g_exit_status = 2;
				fork_aux(pl, st_env);
				exit(1);
			}
			exec_command_or_builtin(&pl->cmds[i], st_env, pl, pipes);
		}
	}
}

void	run_pipeline(t_pipeline *pl, t_env *st_env)
{
	int		**pipes;
	int		i;

	pipes = create_pipes(pl->count);
	pl->pids = malloc(sizeof(pid_t) * pl->count);
	if (!pl->pids || !pipes)
		return ;
	fork_commands(pl, pipes, st_env);
	close_all_pipes(pipes, pl->count);
	i = 0;
	while (i < pl->count)
	{
		waitpid(pl->pids[i], NULL, 0);
		i++;
	}
	free(pl->pids);
	i = 0;
	while (i < pl->count - 1)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
	g_exit_status = 0;
}
