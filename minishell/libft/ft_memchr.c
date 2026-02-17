/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:17:38 by chanin            #+#    #+#             */
/*   Updated: 2025/04/21 19:17:40 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*m;

	i = 0;
	m = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == m[i])
		{
			return ((void *)&m[i]);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	a[29] = "Hay una mosca sobre mi hombro";
	char	b = 'H';
	char	c = 'h';
	char	d = 'a';
	char	e = 'y';
	char	f = 's';
	char	g = 'z';
	char	i = ' ';
	
	ft_memchr(a, b, 2);
	printf("%sc\n\n", ft_memchr(a, c, 2));
	printf("%sd\n\n", ft_memchr(a, d, 2));
	printf("%se\n\n", ft_memchr(a, e, 2));
	printf("%sf\n\n", ft_memchr(a, f, 2));
	printf("%sg\n\n", ft_memchr(a, g, 2));
	printf("%si\n\n", ft_memchr(a, i, 10));

	return (0);
}*/

/*char	*ft_memchr(char *str, char to_find, int n)
{
	int	i;

	i = 0;
	if ((to_find == 0) && (str))
		return (str);
	while (str && str[i] && i < n)
	{
		if (to_find == str[i])
			return (&str[i]);
		i++;		
	}
	return (NULL);
}*/

/*int	main(void)
{
	char	a[29] = "Hay una mosca sobre mi hombro";
	char	b = 'H';
	char	c = 'h';
	char	d = 'a';
	char	e = 'y';
	char	f = 's';
	char	g = 'z';
	char	i = ' ';
	
	printf("%sb\n\n", ft_memchr(a, b, 2));
	printf("%sc\n\n", ft_memchr(a, c, 2));
	printf("%sd\n\n", ft_memchr(a, d, 2));
	printf("%se\n\n", ft_memchr(a, e, 2));
	printf("%sf\n\n", ft_memchr(a, f, 2));
	printf("%sg\n\n", ft_memchr(a, g, 2));
	printf("%si\n\n", ft_memchr(a, i, 10));

	return (0);
}*/
