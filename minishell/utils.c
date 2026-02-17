/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:48:38 by almaldon          #+#    #+#             */
/*   Updated: 2025/09/17 11:46:06 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_mini(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof (char));
	if (!s3)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	s3[i] = '/';
	i++;
	while (s2 && s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

t_builtin	identify_builtin(char *cmd)
{
	if (!cmd)
		return (BUILTIN_NONE);
	if (ft_strcmp(cmd, "echo") == 0)
		return (BUILTIN_ECHO);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (BUILTIN_PWD);
	if (ft_strcmp(cmd, "env") == 0)
		return (BUILTIN_ENV);
	if (ft_strcmp(cmd, "export") == 0)
		return (BUILTIN_EXPORT);
	if (ft_strcmp(cmd, "unset") == 0)
		return (BUILTIN_UNSET);
	if (ft_strcmp(cmd, "cd") == 0)
		return (BUILTIN_CD);
	if (ft_strcmp(cmd, "exit") == 0)
		return (BUILTIN_EXIT);
	return (BUILTIN_NONE);
}

char	*next_token(char **str, const char *delim)
{
	char	*start;
	char	*end;

	if (*str == NULL || **str == '\0')
		return (NULL);
	start = *str;
	end = start;
	while (*end && !ft_strchr(delim, *end))
		end++;
	if (*end)
	{
		*end = '\0';
		*str = end + 1;
	}
	else
		*str = NULL;
	return (start);
}

int	contains_pipe(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], "|") == 0)
			return (1);
		i++;
	}
	return (0);
}

void	free_command(t_command *cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd->argv[i])
		free(cmd->argv[i++]);
	j = -1;
	while (++j < cmd->redirect_count)
		free(cmd->redirects[j].file);
	cmd->redirect_count = 0;
}
