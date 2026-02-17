/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/17 10:59:25 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

bool	ft_find_paths(char **env)
{
	int		i;
	char	*allpaths;

	i = 0;
	allpaths = NULL;
	while (env && env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			allpaths = &env[i][5];
		i++;
	}
	if (!allpaths)
		return (0);
	return (1);
}

static char	**ft_env_3_aux(char *str_env)
{
	int		k;
	char	**new_env;

	k = ft_strchr_4(str_env, '=');
	new_env = malloc(sizeof(char *) * 3);
	if (!new_env)
		return (0);
	if (k != -1)
	{
		new_env[0] = ft_substr(str_env, 0, k);
		new_env[1] = ft_substr(str_env, k + 1, ft_strlen(str_env) - (k + 1));
		new_env[2] = NULL;
		if (!new_env[0] || !new_env[1])
			return (0);
	}
	else
	{
		new_env[0] = ft_strdup(str_env);
		new_env[1] = NULL;
		new_env[2] = NULL;
		if (!new_env[0])
			return (0);
	}
	return (new_env);
}

char	***ft_env_3(char **env)
{
	int		i;
	char	***new_env;

	i = 0;
	new_env = malloc(sizeof(char **) * (ft_size_matrix(env) + 1));
	if (!new_env)
		return (NULL);
	while (env && env[i])
	{
		new_env[i] = ft_env_3_aux(env[i]);
		if (!new_env[i])
			return (ft_free_3pters(new_env));
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

//token = ft_first_split(input);
char	**ft_tokenization(char *input, char ***env)
{
	char	**token;

	token = ft_quotes(input);
	if (!token)
		return (NULL);
	token = ft_split_minishell(token);
	if (!token)
		return (NULL);
	token = ft_expansion(token, env);
	if (!token)
		return (NULL);
	token = ft_clean_matrix(token, " ");
	if (!token)
		return (NULL);
	token = ft_clean_matrix(token, "");
	if (!token)
		return (NULL);
	return (token);
}

/*int	main(int argc, char **argv, char **env)
{
	char		*input;
	char		**tokens;
	char		***env_3;
	char		**copy_env;
	t_command	cmd;
	t_pipeline	pl;
	t_env		st_env;

	(void)argc;
	(void)argv;
	env_3 = NULL;
	copy_env = ft_matrixdup(env);
	if (!copy_env)
		return (1);
	env_3 = ft_env_3(copy_env);
	if (!env_3)
		return (ft_free_stuff("m", copy_env), 1);
	ft_sigaction();
	while (1)
	{
		input = readline(CYAN"minishell ~ $> "RESET);
		if (input == NULL)
			break ;
		add_history(input);
		tokens = ft_tokenization(input, env_3);
		if (tokens)
		{
			if (contains_pipe(tokens))
			{
				if (parse_pipeline(tokens, &pl) == 0)
				{
					ft_free_matrix(tokens);
					st_env.env = copy_env;
					st_env.env_matrix = env_3;
					st_env.env_3 = env_3;
					run_pipeline(&pl, &st_env);
				}
				else
				{
					ft_free_matrix(tokens);
					fprintf(stderr, "Error parsing pipeline\n");
				}
				free_pipeline(&pl);
			}
			else
			{
				if (parse_command(tokens, &cmd) == 0)
					run_command(&cmd, &copy_env, env_3);
				else
					fprintf(stderr, "");
				free_command(&cmd);
			}
		}
		ft_free_stuff("3", env_3);
		env_3 = ft_env_3(copy_env);
		if (!env_3)
			return (ft_free_stuff("m", copy_env), 1);
	}
	write(1, "exit\n", 5);
	ft_free_stuff("m3", copy_env, env_3);
	rl_clear_history();
	return (0);
}*/

/*char	**ft_execute_built_in(char **command, char **copy_env,
	char ***env_3, int *status)
{
	int		i;
	char	**back_up;

	i = 0;
	back_up = ft_matrixdup(copy_env);
	if (!back_up)
		return (printf("Error"), ft_free_stuff("m", copy_env), NULL);
	while (command && command[i])
	{
		if (ft_strcmp(command[i], "pwd") == 0)
			ft_pwd();
		else if (ft_strcmp(command[i], "env") == 0)
			ft_env(copy_env);
		//i++ por cada palabra escrita ?
		else if (ft_strcmp(command[i], "echo") == 0
				&& command[i + 1] && ft_strcmp(command[i + 1], "-n") == 0
				&& command[i + 2] && command[i + 2])
			ft_echo_n(&command[i + 2]);
		//i++ por cada palabra escrita ?
		else if (ft_strcmp(command[i], "echo") == 0 && command[i + 1])
			ft_echo(&command[i + 1]);
		else if (ft_strcmp(command[i], "unset") == 0 && command[i + 1])
		{
			copy_env = ft_unset(command[i + 1], copy_env);
			if (!copy_env)
			{
				*status = -1;
				return (ft_free_stuff("mm", command, copy_env), back_up);
			}
			i++;
		}
		else if (ft_strcmp(command[i], "export") == 0 && command[i + 1])
		{
			copy_env = ft_export_1(copy_env, command[i + 1], env_3);
			if (!copy_env)
			{
				//free ?
				return (ft_free_stuff("mm", command, copy_env), back_up);
			}
			i++;
		}
		else if (ft_strcmp(command[i], "export") == 0 )
			ft_export_0(copy_env);
		else if (ft_strcmp(command[i], "cd") == 0 && command[i + 1])
		{
			copy_env = ft_cd(command[i + 1], copy_env, env_3);
			if (!copy_env)
			{
				//free ?
				printf("cd: problemoss\n");
				*status = -1;
				return (ft_free_stuff("mm", command, copy_env), back_up);
			}
			i++;
		}
		else if (ft_strcmp(command[i], "exit") == 0)
		{
			ft_free_stuff("mm", back_up, copy_env);          //free mas cosas
			exit(*status);
		}
		else	
		{
			printf("%s: command not found\n", command[i]);
			return (ft_free_stuff("mm", command, copy_env), back_up);
		}
		i++;
	}
	ft_free_stuff("mm", command, back_up);
	return (copy_env);
}*/
