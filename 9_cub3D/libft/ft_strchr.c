/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:17:38 by chanin            #+#    #+#             */
/*   Updated: 2025/08/12 11:44:09 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

/* Looks for a char in a string
 * Returns its positions
 * Returns -1 if not found */
int	ft_strchr_4(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
			return (i);
		i++;
	}
	if ((unsigned char)c == 0)
		return (i);
	return (-1);
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
	
	printf("%sb\n\n", ft_strchr(a, b));
	printf("%sc\n\n", ft_strchr(a, c));
	printf("%sd\n\n", ft_strchr(a, d));
	printf("%se\n\n", ft_strchr(a, e));
	printf("%sf\n\n", ft_strchr(a, f));
	printf("%sg\n\n", ft_strchr(a, g));
	printf("%si\n\n", ft_strchr(a, i));

	return (0);
}*/

/*char	*ft_strchr(char *str, char to_find)
{
	int	i;

	i = 0;
	if ((to_find == 0) && (str))
		return (str);
	while (str && str[i])
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
	
	printf("%sb\n\n", ft_strchr(a, b));
	printf("%sc\n\n", ft_strchr(a, c));
	printf("%sd\n\n", ft_strchr(a, d));
	printf("%se\n\n", ft_strchr(a, e));
	printf("%sf\n\n", ft_strchr(a, f));
	printf("%sg\n\n", ft_strchr(a, g));
	printf("%si\n\n", ft_strchr(a, i));

	return (0);
}*/
