/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/17 12:49:47 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_main_exec_2(char **tokens, t_env *st_env, t_command *cmd)
{
	if (parse_command(tokens, cmd) == 0)
		run_command(cmd, &st_env->env, st_env->env_3);
	else
	{
		g_exit_status = 2;
		write(2, "", 0);
	}
	free_command(cmd);
}

int	ft_main_exec(char **tokens, t_env *st_env, t_command *cmd)
{
	t_pipeline	pl;

	if (contains_pipe(tokens))
	{
		if (parse_pipeline(tokens, &pl) == 0)
		{
			ft_free_matrix(tokens);
			run_pipeline(&pl, st_env);
		}
		else
		{
			g_exit_status = 2;
			return (ft_free_matrix(tokens), write(2, "Error: Pipe\n", 12));
		}
		free_pipeline(&pl);
	}
	else
	{
		ft_main_exec_2(tokens, st_env, cmd);
	}
	return (0);
}

void	ft_main_exit(char ***env_3, char **copy_env)
{
	write(1, "exit\n", 5);
	ft_free_stuff("m3", copy_env, env_3);
	rl_clear_history();
}

int	ft_main_init(char ***argv, char ***env, char ****env_3, char ***copy_env)
{
	(void)*argv;
	*env_3 = NULL;
	*copy_env = ft_matrixdup(*env);
	if (!*copy_env)
		return (0);
	*env_3 = ft_env_3(*copy_env);
	if (!*env_3)
		return (ft_free_stuff("m", *copy_env), 0);
	ft_sigaction();
	return (1);
}

//ls -l | grep utils | wc -l > 1.txt
int	main(int argc, char **argv, char **env)
{
	char		*input;
	char		**tokens;
	t_command	cmd;
	t_env		st_env;

	(void)argc;
	if (ft_main_init(&argv, &env, &st_env.env_3, &st_env.env) == 0)
		return (0);
	while (1)
	{
		input = readline(CYAN"minishell ~ $> "RESET);
		if (input == NULL)
			break ;
		add_history(input);
		tokens = ft_tokenization(input, st_env.env_3);
		if (tokens)
			ft_main_exec(tokens, &st_env, &cmd);
		ft_free_stuff("3", st_env.env_3);
		st_env.env_3 = ft_env_3(st_env.env);
		if (!st_env.env_3)
			return (ft_free_stuff("m", st_env.env), 1);
	}
	return (ft_main_exit(st_env.env_3, st_env.env), 0);
}
