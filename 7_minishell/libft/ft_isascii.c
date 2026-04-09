/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:43:02 by chanin            #+#    #+#             */
/*   Updated: 2025/03/28 13:43:04 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

/*int	main(void)
{
	printf ("%d", ft_isascii('f'));
	return(0);
}*/

/*int	ft_isascii(char *str)     
{
	while (str && *str)
	{
		if (*str <= 0 || *str >= 127)
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
*/

/*int	main(void)
{
	char a[3] = "";
	char b[4] = "Qu\31";
	char c[5] = "!!\15!";
	char d[3] = " ~";
	char e[3] = "\8";
	
	printf ("%d", ft_isascii(&a[0]));
	printf ("%d", ft_isascii(&b[0]));
	printf ("%d", ft_isascii(&c[0]));
	printf ("%d", ft_isascii(&d[0]));
	printf ("%d", ft_isascii(&e[0]));
	return(0);
}*/
