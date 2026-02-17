/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:55:24 by chanin            #+#    #+#             */
/*   Updated: 2025/03/28 13:55:26 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

/*int	main(void)
{
	printf ("%c\n\n", ft_toupper('g'));
	return(0);
}*/

/*char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}*/

/*int	main(void)
{
	char a[3] = "az";
	char b[4] = "Que";
	char c[6] = "ue Qj";
	char d[3] = "QQ";
	char e[3] = "";
	
	ft_strupcase(&a[0]);
	printf ("%s\n\n", ft_strupcase(&a[0]));
	ft_strupcase(&b[0]);
	printf ("%s\n\n", b);
	ft_strupcase(&c[0]);
	printf ("%s\n\n", c);
	ft_strupcase(&d[0]);
	printf ("%s\n\n", d);
	ft_strupcase(&e[0]);
	printf ("%s\n\n", e);
	return(0);
}*/
