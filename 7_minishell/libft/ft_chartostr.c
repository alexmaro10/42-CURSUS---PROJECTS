/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/08/08 15:20:56 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* transforms a char into a string with the null */
char	*ft_chartostr(char a)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[i] = a;
	i++;
	str[i] = '\0';
	return (str);
}
