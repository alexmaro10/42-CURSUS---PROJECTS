/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_find_comand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:16:30 by almaldon          #+#    #+#             */
/*   Updated: 2025/09/11 09:04:20 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*check_direct_command(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (NULL);
}

static char	*search_in_path(char *cmd)
{
	char	*path_env;
	char	*paths;
	char	*dir;
	char	*full_path;
	char	*cursor;

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);
	paths = ft_strdup(path_env);
	if (!paths)
		return (NULL);
	cursor = paths;
	dir = next_token(&cursor, ":");
	while (dir)
	{
		full_path = ft_strjoin_mini(dir, cmd);
		if (access(full_path, X_OK) == 0)
			return (free(paths), full_path);
		free(full_path);
		dir = next_token(&cursor, ":");
	}
	return (free(paths), NULL);
}

char	*find_command_path(char *cmd)
{
	char	*result;

	result = check_direct_command(cmd);
	if (result)
		return (result);
	return (search_in_path(cmd));
}
