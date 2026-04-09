/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/08/14 19:11:44 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split_minishell_aux_1(char	**matrix, int *i, char const *sign)
{
	char	*temp;

	temp = ft_strdup(sign);
	if (!temp)
		return (ft_free_stuff("m", matrix));
	matrix = ft_addstring(matrix, temp);
	if (!matrix)
		return (ft_free_stuff("s", temp));
	free(temp);
	(*i)++;
	return (matrix);
}

char	**ft_split_minishell_aux_2(char	**matrix, char const sign)
{
	char	*str;

	str = ft_chartostr(sign);
	if (!str)
		return (ft_free_stuff("m", matrix));
	matrix = ft_addstring(matrix, str);
	if (!matrix)
		return (ft_free_stuff("s", str));
	free(str);
	return (matrix);
}

char	**ft_split_minishell_aux_3(char	**matrix, char *string, int *i)
{
	int		start;
	char	*temp;

	start = *i;
	while (string[*i] && string[*i] != '|' && string[*i] != '>'
		&& string[*i] != '<' && string[*i] != ' ')
		(*i)++;
	temp = ft_substr(string, start, *i - start);
	if (!temp)
		return (ft_free_stuff("m", matrix));
	matrix = ft_addstring(matrix, temp);
	if (!matrix)
		return (ft_free_stuff("s", temp));
	free(temp);
	return (matrix);
}

/* Depending on the signs, creates a new matrix */
char	**ft_split_minishell_aux(char *string)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = NULL;
	while (string && string[i])
	{
		if (string[i] == '|' || string[i] == '>'
			|| string[i] == '<' || string[i] == ' ')
		{
			if (string[i] == '>' && string[i + 1] && string[i + 1] == '>')
				matrix = ft_split_minishell_aux_1(matrix, &i, ">>");
			else if (string[i] == '<' && string[i + 1] && string[i + 1] == '<')
				matrix = ft_split_minishell_aux_1(matrix, &i, "<<");
			else
				matrix = ft_split_minishell_aux_2(matrix, string[i]);
			i++;
		}
		else
			matrix = ft_split_minishell_aux_3(matrix, string, &i);
		if (!matrix)
			return (NULL);
	}
	return (matrix);
}

char	**ft_split_minishell(char **token)
{
	int		i;
	char	**split;
	char	**new_token;

	i = 0;
	new_token = NULL;
	while (token && token[i])
	{
		if (token[i][0] == 34 || token[i][0] == 39)
			new_token = ft_addstring(new_token, token[i]);
		else
		{
			split = ft_split_minishell_aux(token[i]);
			if (!split)
				return (ft_free_stuff("mm", new_token, token));
			new_token = ft_addmatrix(new_token, split);
			if (!new_token)
				return (ft_free_stuff("mmm", new_token, token, split));
			ft_free_matrix(split);
		}
		i++;
	}
	ft_free_matrix(token);
	return (new_token);
}
