/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run_built_in.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 08:31:54 by almaldon          #+#    #+#             */
/*   Updated: 2025/09/17 11:25:39 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static bool	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_free_utils(char ***envp_matrix, char ***env_3, t_command *cmd)
{
	ft_free_stuff("m3", *envp_matrix, env_3);
	free_command(cmd);
}

static int	run_builtin_help_2(t_command *cmd, char ***envp_matrix,
	t_builtin b, char ***env_3)
{
	char	*path;

	if (b == BUILTIN_CD)
	{
		if (cmd->argv[1])
			path = cmd->argv[1];
		else
			path = getenv("HOME");
		*envp_matrix = ft_cd(path, *envp_matrix, env_3);
	}
	else if (b == BUILTIN_EXIT)
	{
		if (cmd->argv[1] && ft_isnum(cmd->argv[1]))
			g_exit_status = ft_atoi(cmd->argv[1]);
		else if (cmd->argv[1] && !ft_isnum(cmd->argv[1]))
		{
			printf("exit: numeric argument required\n");
			g_exit_status = 2;
		}
		else
			g_exit_status = 0;
		ft_free_utils(envp_matrix, env_3, cmd);
		exit(g_exit_status);
	}
	return (0);
}

static int	run_builtin_helper(t_command *cmd, char ***envp_matrix,
	t_builtin b, char ***env_3)
{
	if (b == BUILTIN_ECHO)
	{
		if (cmd->argv[1] && ft_strcmp(cmd->argv[1], "-n") == 0)
			ft_echo_n(&cmd->argv[2]);
		else
			ft_echo(&cmd->argv[1]);
	}
	else if (b == BUILTIN_PWD)
		ft_pwd();
	else if (b == BUILTIN_ENV)
		ft_env(*envp_matrix);
	else if (b == BUILTIN_EXPORT)
	{
		if (!cmd->argv[1])
			ft_export_0(*envp_matrix);
		else
			*envp_matrix = ft_export_1(*envp_matrix,
					cmd->argv[1], env_3);
	}
	else if (b == BUILTIN_UNSET)
		*envp_matrix = ft_unset(cmd->argv[1], *envp_matrix);
	return (run_builtin_help_2(cmd, envp_matrix, b, env_3));
}

int	run_builtin(t_command *cmd, char ***envp_matrix, char ***env_3)
{
	int			saved_stdin;
	int			saved_stdout;
	t_builtin	b;

	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	if (apply_redirections(cmd) < 0)
		return (-1);
	b = identify_builtin(cmd->argv[0]);
	run_builtin_helper(cmd, envp_matrix, b, env_3);
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
	return (0);
}
