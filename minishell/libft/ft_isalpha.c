/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:33:50 by chanin            #+#    #+#             */
/*   Updated: 2025/03/28 10:34:15 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 'A') || (c > 'Z' && c < 'a') || (c > 'z'))
		return (0);
	return (1);
}

/*int	main(void)
{
	printf ("%d", ft_isalpha('k'));
	return(0);
}*/

/*int	ft_str_is_alpha(char *str)
{
	while (str && *str)
	{
		if ((*str < 'A') || (*str > 'Z' && *str < 'a') || (*str > 'z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}*/

/*int	isalpha(int c)
{
	if ((c - '0' < 'A') || (c - '0' > 'Z' && c - '0' < 'a') || (c - '0' > 'z'))
	{
		return (0);
	}
	return (1);
}*/

/*int	a;

	a = 0;
	printf ("%d", a);
			
	a = 1;
	printf ("%d", a);
*/
/*int	main(void)
{
	char a[3] = "";
	char b[4] = "Qu3";
	char c[5] = "!!!!";
	char d[3] = "iP";
	char e[3] = "03";
	
	ft_str_is_alpha(&a[0]);
	printf ("%d", ft_str_is_alpha(a));
	ft_str_is_alpha(&b[0]);
	printf ("%d", ft_str_is_alpha(b));
	ft_str_is_alpha(&c[0]);
	printf ("%d", ft_str_is_alpha(c));
	ft_str_is_alpha(&d[0]);
	printf ("%d", ft_str_is_alpha(d));
	ft_str_is_alpha(&e[0]);
	printf ("%d", ft_str_is_alpha(e));
	return(0);
}*/
