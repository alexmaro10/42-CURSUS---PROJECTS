/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:06:22 by chanin            #+#    #+#             */
/*   Updated: 2025/03/28 13:06:30 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

/*int	ft_str_is_numeric(char *str)
{
	while (str && *str)
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}
	return (1);
}*/

/*	int	a;

	a = 0;
	printf ("%d", a);
			
	a = 1;
	printf ("%d", a);

int	main(void)
{
	char a[3] = "";
	char b[4] = "Que";
	char c[5] = "!!!!";
	char d[3] = "24";
	char e[3] = "03";
	
	ft_str_is_numeric(&a[0]);
	ft_str_is_numeric(&b[0]);
	ft_str_is_numeric(&c[0]);
	ft_str_is_numeric(&d[0]);
	ft_str_is_numeric(&e[0]);

	return(0);
}*/
