/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/17 11:26:30 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

char	*ft_expand(char *str, int start, char ***env, int end)
{
	int		i;
	size_t	len;
	char	*new_str;

	i = 0;
	if (ft_strncmp(&str[start], "?", 1) == 0)
		return (ft_itoa(g_exit_status));
	len = end - start;
	while (env && env[i])
	{
		if (ft_strlen(env[i][0]) == len
			&& ft_strncmp(&str[start], env[i][0], len) == 0)
		{
			new_str = ft_strdup(env[i][1]);
			if (!new_str)
				return (ft_free_stuff("s", str));
			return (new_str);
		}
		i++;
	}
	new_str = ft_strdup("");
	if (!new_str)
		return (NULL);
	return (new_str);
}

char	*ft_expansion_aux_2(char *str, char ***env, int j, int k)
{
	char	*before;
	char	*expanded;
	char	*after;

	expanded = ft_expand(str, j + 1, env, k);
	if (expanded)
	{
		before = ft_substr(str, 0, j);
		after = ft_substr(str, k, ft_strlen(str) - k);
		if (!before || !after)
			return (ft_free_stuff("sss", before, expanded, after));
		free(str);
		str = ft_strjoin_var(3, before, expanded, after);
		if (!str)
			return (ft_free_stuff("sss", before, expanded, after));
		ft_free_stuff("sss", before, expanded, after);
		return (str);
	}
	return (str);
}

int	ft_in_or_out(int in, char c)
{
	if (c == '\"' && in == 0)
		in = 1;
	else if (c == '\'' && in == 0)
		in = -1;
	else if (c == '\"' && in == 1)
		in = 0;
	else if (c == '\'' && in == -1)
		in = 0;
	return (in);
}

char	*ft_expansion_aux_1(int *in, char *str, int *j, char ***env)
{
	int	end;

	*in = ft_in_or_out(*in, str[*j]);
	if (str[*j] == '$' && str[*j + 1]
		&& (ft_isalnum(str[*j + 1]) || str[*j + 1] == '?') && *in != -1)
	{
		end = *j + 1;
		if (str[end] == '?')
			end++;
		else
			while (str[end] && (ft_isalnum(str[end]) || str[end] == '_'))
				end++;
		str = ft_expansion_aux_2(str, env, *j, end);
		if (!str)
			return (NULL);
		*j = -1;
		*in = 0;
	}
	return (str);
}

char	**ft_expansion(char **token, char ***env)
{
	int		i;
	int		j;
	int		in;

	i = 0;
	in = 0;
	while (token && token[i])
	{
		j = 0;
		while (token[i][j])
		{
			token[i] = ft_expansion_aux_1(&in, token[i], &j, env);
			if (!token[i])
				return (ft_free_stuff("m", token));
			j++;
		}
		token[i] = ft_clean_token(token[i]);
		if (!token[i])
			return (ft_free_stuff("m", token));
		i++;
	}
	return (token);
}
