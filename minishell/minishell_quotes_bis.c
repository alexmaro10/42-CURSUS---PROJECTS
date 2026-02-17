/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quotes_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/11 08:36:40 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_first_split_aux(char *input, int *start, int *end, int *in)
{
	while (input[*start] == ' ')
		(*start)++;
	if (!input[*start])
		return (0);
	*end = *start;
	while (input[*end])
	{
		*in = ft_in_or_out(*in, input[*end]);
		if (input[*end] == ' ' && *in == 0)
			break ;
		(*end)++;
	}
	return (1);
}

char	**ft_first_split(char *input)
{
	int		start;
	int		end;
	int		in;
	char	**token;
	char	*new_str;

	start = 0;
	in = 0;
	token = NULL;
	while (input && input[start])
	{
		if (ft_first_split_aux(input, &start, &end, &in) == 0)
			break ;
		new_str = ft_substr(input, start, end - start);
		if (!new_str)
			return (ft_free_stuff("m", token));
		token = ft_addstring(token, new_str);
		if (!token)
			return (ft_free_stuff("s", new_str));
		start = end;
	}
	return (token);
}
