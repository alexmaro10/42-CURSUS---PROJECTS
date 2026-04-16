/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:09:21 by chanin            #+#    #+#             */
/*   Updated: 2025/04/21 15:09:25 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c < 'A') || (c > 'Z' && c < 'a') || (c > 'z'))
		&& (c < '0' || c > '9'))
		return (0);
	return (1);
}

/*int	main(void)
{
	//char a[3] = "";
	//char b[3] = "0i";
	char c[5] = "!!!!";
	char d[3] = "i";
	char e[3] = "0";
	
	//printf ("%d", ft_isalnum(a));
	printf ("%d", ft_isalnum('d'));
	printf ("%d", ft_isalnum(c));
	printf ("%d", ft_isalnum(d));
	printf ("%d", ft_isalnum(e));
	return(0);
}*/

/*int	ft_isalnum(char *str)
{
	while (str && *str)
	{
		if (((*str < 'A') || (*str > 'Z' && *str < 'a') || (*str > 'z'))
			&& (*str < '0' || *str > '9'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}*/

/*int	main(void)
{
	//char a[3] = "";
	char b[3] = "0i";
	char c[5] = "!!!!";
	char d[3] = "i";
	char e[3] = "0";
	
	//printf ("%d", ft_isalnum(a));
	//printf ("%d", ft_isalnum(b));
	printf ("%d", ft_isalnum(c));
	printf ("%d", ft_isalnum(d));
	printf ("%d", ft_isalnum(e));
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
}

int	ft_str_is_numeric(char *str)
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
}

int	ft_isalnum(char *str)
{
	while (str && *str)
	{
		write(1, "b", 1);
		if (ft_str_is_numeric(str) == 0 && ft_str_is_alpha(str) == 0)
		{
			write(1, "a", 1);
			return (0);
		}
		str++;
	}
	return (1);
}*/
