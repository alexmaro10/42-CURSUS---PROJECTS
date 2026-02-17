/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_expand_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/08/19 14:05:52 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_clean_token(char *str)
{
	char	*quote;
	char	*tmp;

	if (!str || !str[0])
		return (str);
	if (str[0] == '"' || str[0] == '\'')
	{
		quote = ft_chartostr(str[0]);
		if (!quote)
			return (NULL);
		tmp = ft_strtrim(str, quote);
		if (!tmp)
			return (ft_free_stuff("s", quote));
		free(str);
		ft_free_stuff("s", quote);
		return (tmp);
	}
	return (str);
}
