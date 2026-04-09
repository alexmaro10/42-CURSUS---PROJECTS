/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:05:58 by chanin            #+#    #+#             */
/*   Updated: 2025/04/01 19:07:10 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/*int	main(void)
{
	printf ("%c\n\n", ft_tolower('P'));
	return(0);
}*/

/*char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}*/

/*int	main(void)
{
	char a[3] = "AZ";
	char b[4] = "Que";
	char c[6] = "ue Qj";
	char d[3] = "QQ";
	char e[3] = "";
	
	ft_strlowcase(&a[0]);
	printf ("%s\n\n", a);
	ft_strlowcase(&b[0]);
	printf ("%s\n\n", b);
	ft_strlowcase(&c[0]);
	printf ("%s\n\n", c);
	ft_strlowcase(&d[0]);
	printf ("%s\n\n", d);
	ft_strlowcase(&e[0]);
	printf ("%s\n\n", e);
	return(0);
}*/
