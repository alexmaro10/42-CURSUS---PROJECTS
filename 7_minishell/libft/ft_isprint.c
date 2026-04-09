/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:43:02 by chanin            #+#    #+#             */
/*   Updated: 2025/03/28 13:43:04 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

/*	int	a;
	
	a = 0;
	printf ("%d", a);
			
	a = 1;
	printf ("%d", a);


int	main(void)
{
	char a[3] = "";
	char b[4] = "Qu\31";
	char c[5] = "!!\15!";
	char d[3] = " ~";
	char e[3] = "\00\127";
	
	ft_str_is_printable(&a[0]);
	ft_str_is_printable(&b[0]);
	ft_str_is_printable(&c[0]);
	ft_str_is_printable(&d[0]);
	ft_str_is_printable(&e[0]);
	return(0);
}*/
