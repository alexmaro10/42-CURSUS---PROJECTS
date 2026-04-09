/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:22:00 by chanin            #+#    #+#             */
/*   Updated: 2025/08/14 19:06:34 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i]
			|| s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!(*s1))
		return (-1);
	while ((s1 && *s1) && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}*/

/*int	main(void)
{
	char *a = "abcd";
	char *b = "ABcd";
	char *c = "abcdefgH";
	char *d = "abc";

	ft_strncmp(a, b, 4);
	printf("%d\n\n", ft_strncmp(a, b, 4));
	ft_strncmp(a, c, 4);
	printf("%d\n\n", ft_strncmp(a, c, 4));
	ft_strncmp(a, d, 4);
	printf("%d\n\n", ft_strncmp(a, d, 4));
	ft_strncmp(b, c, 4);
	printf("%d\n\n", ft_strncmp(b, c, 4));
	ft_strncmp(b, d, 4);
	printf("%d\n\n", ft_strncmp(b, d, 4));
	ft_strncmp(c, d, 4);
	printf("%d\n\n", ft_strncmp(c, d, 4));
	return (0);
}*/

/*int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1 && *s1) && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}*/

/*int	main(void)
{
	char *a = "abcd";
	char *b = "ABcd";
	char *c = "abcdefgH";
	char *d = "abc";

	ft_strncmp(a, b, 4);
	printf("%d\n\n", ft_strncmp(a, b, 4));
	ft_strncmp(a, c, 4);
	printf("%d\n\n", ft_strncmp(a, c, 4));
	ft_strncmp(a, d, 4);
	printf("%d\n\n", ft_strncmp(a, d, 4));
	ft_strncmp(b, c, 4);
	printf("%d\n\n", ft_strncmp(b, c, 4));
	ft_strncmp(b, d, 4);
	printf("%d\n\n", ft_strncmp(b, d, 4));
	ft_strncmp(c, d, 4);
	printf("%d\n\n", ft_strncmp(c, d, 4));
	return (0);
}*/
