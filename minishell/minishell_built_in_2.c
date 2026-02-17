/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_built_in_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/17 12:18:38 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_unset(char *unwanted, char **env)
{
	char	*str;
	int		i;
	int		len;
	char	**new_env;

	if (!unwanted)
		return (env);
	i = -1;
	len = ft_strlen(unwanted);
	str = NULL;
	while (env && env[++i])
	{
		if (ft_strncmp(env[i], unwanted, len) == 0)
		{
			str = ft_strdup(env[i]);
			if (!str)
				return (ft_free_stuff("m", env));
			break ;
		}
	}
	if (!env[i])
		return (env);
	new_env = ft_clean_matrix(env, str);
	return (ft_free_stuff("s", str), new_env);
}

char	**ft_cd_2_aux(char *dir, char **env, char ***env_3, int pos_pwd)
{
	char	*oldpwd;
	char	*pwd;
	char	***env_3_new;

	oldpwd = ft_strjoin_var(2, "OLDPWD=", env_3[pos_pwd][1]);
	pwd = ft_strjoin_var(2, "PWD=", dir);
	if (!oldpwd || !pwd)
		return (ft_free_stuff("ss", oldpwd, pwd));
	env = ft_unset("OLDPWD", env);
	if (!env)
		return (ft_free_stuff("ss", oldpwd, pwd));
	env = ft_unset("PWD", env);
	if (!env)
		return (ft_free_stuff("ss", oldpwd, pwd));
	env_3_new = ft_env_3(env);
	if (!*env_3_new)
		return (ft_free_stuff("ss", oldpwd, pwd));
	env = ft_export_1(env, oldpwd, env_3_new);
	if (!env)
		return (ft_free_stuff("ss", oldpwd, pwd));
	env = ft_export_1(env, pwd, env_3_new);
	if (!env)
		return (ft_free_stuff("ss", oldpwd, pwd));
	return (ft_free_stuff("ss3", oldpwd, pwd, env_3_new), env);
}

char	**ft_cd_2(char *dir, char **env, char ***env_3)
{
	int		pos_oldpwd;
	int		pos_pwd;
	char	*pwd;

	pos_oldpwd = ft_export_1_aux(env_3, "OLDPWD");
	pos_pwd = ft_export_1_aux(env_3, "PWD");
	if (pos_pwd < 0 && pos_oldpwd < 0)
		return (env);
	else if (pos_oldpwd < 0 || ((pos_pwd >= 0) && !env_3[pos_pwd][1]))
	{
		pwd = ft_strjoin_var(2, "PWD=", dir);
		if (!pwd)
			return (NULL);
		env = ft_export_1(env, pwd, env_3);
		return (ft_free_stuff("s", pwd), env);
	}
	else if (pos_pwd < 0)
	{
		env = ft_unset("OLDPWD", env);
		if (!env)
			return (NULL);
		return (ft_addstring(env, "OLDPWD"));
	}
	return (ft_cd_2_aux(dir, env, env_3, pos_pwd));
}

char	**ft_cd(char *dir, char **env, char ***env_3)
{
	char	cwd[1024];
	char	**new_env;

	new_env = NULL;
	if (chdir(dir) != 0)
	{
		perror("cd");
		return (NULL);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		new_env = ft_cd_2(cwd, env, env_3);
		if (!new_env)
			return (NULL);
	}
	else
		perror("getcwd");
	return (new_env);
}
