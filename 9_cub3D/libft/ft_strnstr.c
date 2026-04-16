/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:27:19 by chanin            #+#    #+#             */
/*   Updated: 2025/04/02 15:27:24 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	if (little[k] == 0)
		return ((char *)big);
	while (big[k] && k < len)
	{
		j = 0;
		i = k;
		while (i < len && little[j] && little[j] == big[i])
		{
			i++;
			j++;
			if (little[j] == 0)
			{
				return ((char *)&big[k]);
			}
		}
		k++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	a[29] = "Hay una mosca sobre mi hombro";
	char	b[10] = "una mosca";
	char	b2[2] = "s";
	char	c[4] = "Hay";
	char	d[7] = "hombre";
	char	e[6] = "broma";
	char	f[37] = "Hay una mosca sobre mi hombro peludo";
	char	g[30] = "ay una mosca sobre mi hombr";
	char	h[1] = "";
	char	i[1] = "0";
	
	printf("%sb\n\n", ft_strnstr(a, b, 2));
	printf("%sb\n\n", ft_strnstr(a, &b[0], 2));
	printf("%sb\n\n", ft_strnstr(a, &b[1], 2));
	printf("%sb\n\n", ft_strnstr(a, &b[2], 2));
	printf("%sb\n\n", ft_strnstr(a, &b[3], 2));
	printf("%sb\n\n", ft_strnstr(a, &b[4], 2));
	printf("%sb\n\n", ft_strnstr(a, &b[5], 2));
	printf("%sb\n\n", ft_strnstr(a, &b[6], 2));
	printf("%sb\n\n", ft_strnstr(a, &b[7], 2));
	printf("%sb\n\n", ft_strnstr(a, b, 15));
	printf("%sb2\n\n", ft_strnstr(a, b2, 16));
	printf("%sc\n\n", ft_strnstr(a, c, 2));
	printf("%sd\n\n", ft_strnstr(a, d, 2));
	printf("%se\n\n", ft_strnstr(a, e, 2));
	printf("%sf\n\n", ft_strnstr(a, f, 30));
	printf("%sg\n\n", ft_strnstr(a, g, 2));
	printf("%sh\n\n", ft_strnstr(a, h, 2));
	printf("%si\n\n", ft_strnstr(a, i, 2));

	return (0);
}*/

/*char	*ft_strnstr(char *str, char *to_find, int n)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	if ((to_find[k] == 0) && (str))
		return (str);
	while (str && str[k] && k < n)
	{
		j = 0;
		i = k;
		while (to_find[j] == str[i])
		{
			i++;
			j++;
			if (to_find[j] == 0)
				return (&str[k]);
		}
		k++;
	}
	return (NULL);
}*/
