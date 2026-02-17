/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:33:22 by almaldon          #+#    #+#             */
/*   Updated: 2025/09/17 14:35:44 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static void	run_child(t_command *cmd, char **envp, char *path)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (apply_redirections(cmd) < 0)
	{
		g_exit_status = 0;
		exit(1);
	}
	execve(path, cmd->argv, envp);
	perror("execve");
	free(path);
	free_command(cmd);
	ft_free_matrix(envp);
	g_exit_status = 2;
	exit(1);
}

static void	execute_cmd_path(t_command *cmd, char **envp, char *path)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free(path);
		g_exit_status = 2;
		return ;
	}
	if (pid == 0)
		run_child(cmd, envp, path);
	waitpid(pid, &status, 0);
	free(path);
	g_exit_status = 0;
}

void	run_command(t_command *cmd, char ***envp_matrix, char ***env_3)
{
	char		*path;
	t_builtin	b;

	if (ft_find_paths(*envp_matrix))
	{
		path = find_command_path(cmd->argv[0]);
		if (path)
		{
			execute_cmd_path(cmd, *envp_matrix, path);
			g_exit_status = 0;
			return ;
		}
	}
	b = identify_builtin(cmd->argv[0]);
	if (b != BUILTIN_NONE)
	{
		run_builtin(cmd, envp_matrix, env_3);
		g_exit_status = 0;
		return ;
	}
	g_exit_status = 127;
	write(2, cmd->argv[0], ft_strlen(cmd->argv[0]));
	write(2, ": command not found\n", 21);
}
