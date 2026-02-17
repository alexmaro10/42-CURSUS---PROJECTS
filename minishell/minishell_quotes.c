/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/08/26 11:25:19 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_strchr_2(const char *s, char c[2], int d)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c[0] == s[i] && d == 0)
			return (i);
		else if (c[1] == s[i] && d == 1)
			return (i);
		else if ((c[0] == s[i] || c[1] == s[i]) && d == 2)
			return (i);
		i++;
	}
	return (i);
}

bool	ft_quotes_aux(t_quotes	*info, char **input, int type_quote)
{
	char	*element;
	int		if_quote;

	if_quote = 1;
	if (type_quote == 2)
		if_quote = 0;
	info->end = info->start
		+ ft_strchr_2(*input + info->start + if_quote, info->quotes, type_quote)
		+ if_quote;
	element = ft_substr(*input, info->start, info->end - info->start
			+ if_quote);
	if (!element)
	{
		ft_free_matrix(info->token);
		return (0);
	}
	info->token = ft_addstring(info->token, element);
	if (!info->token)
	{
		free (element);
		return (0);
	}
	free (element);
	info->start = info->end + if_quote;
	return (1);
}

void	ft_quotes_init(t_quotes	*info)
{
	info->start = 0;
	info->end = 0;
	info->quotes[0] = 34;
	info->quotes[1] = 39;
	info->token = NULL;
}

char	**ft_quotes(char *input)
{
	t_quotes	info;

	ft_quotes_init(&info);
	if (!input)
		return (NULL);
	while (input && input[info.start])
	{
		if (input[info.start] == 34)
		{
			if (ft_quotes_aux(&info, &input, 0) == 0)
				return (NULL);
		}
		else if (input[info.start] == 39)
		{
			if (ft_quotes_aux(&info, &input, 1) == 0)
				return (NULL);
		}
		else
		{
			if (ft_quotes_aux(&info, &input, 2) == 0)
				return (NULL);
		}
	}
	return (info.token);
}
