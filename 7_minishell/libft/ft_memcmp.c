/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:33:49 by chanin            #+#    #+#             */
/*   Updated: 2025/03/29 22:33:52 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*m;
	unsigned char	*l;

	i = 0;
	m = (unsigned char *)s1;
	l = (unsigned char *)s2;
	while (i < n)
	{
		if (m[i] != l[i])
			return (m[i] - l[i]);
		i++;
	}
	return (0);
}

/*int	ft_memcmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1 && *s1 && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}*/

/*int	main(void)
{
	char *a = "abc";
	char *b = "ABC";
	char *c = "Zbc";
	char *d = "abcd";

	printf("%d\n\n", ft_memcmp(a, b, 2));
	printf("%d\n\n", ft_memcmp(a, c, 2));
	printf("%d\n\n", ft_memcmp(a, d, 4));
	printf("%d\n\n", ft_memcmp(b, c, 2));
	printf("%d\n\n", ft_memcmp(b, d, 2));
	printf("%d\n\n", ft_memcmp(c, d, 2));
	return (0);
}*/
