/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:17:38 by chanin            #+#    #+#             */
/*   Updated: 2025/04/21 19:17:40 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	i = (int)i - 1;
	while (s && s[i] && i >= 0)
	{
		if ((unsigned char)c == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*if ((c == 0) && (s))
		return ((char *)s);*/

/*int	main(void)
{
	char	a[29] = "Hay una mosca sobre mi hombro";
	char	b = 'H';
	char	c = 'h';
	char	d = 'a';
	char	e = 'y';
	char	f = '\0';
	char	g = 'z';
	char	i = ' ';
	
	printf("%sb\n\n", ft_strrchr(a, b));
	printf("%sc\n\n", ft_strrchr(a, c));
	printf("%sd\n\n", ft_strrchr(a, d));
	printf("%se\n\n", ft_strrchr(a, e));
	printf("%sf\n\n", ft_strrchr(a, f));
	printf("%sg\n\n", ft_strrchr(a, g));
	printf("%si\n\n", ft_strrchr(a, i));

	return (0);
}*/

/*char	*ft_strrchr(char *str, char to_find)
{
	int	i;

	i = ft_strlen(str);
	i -= 1;
	if ((to_find == 0) && (str))
		return (str);
	while (str && str[i] && i >= 0)
	{
		if (to_find == str[i])
			return (&str[i]);
		i--;
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
	
	printf("%sb\n\n", ft_strrchr(a, b));
	printf("%sc\n\n", ft_strrchr(a, c));
	printf("%sd\n\n", ft_strrchr(a, d));
	printf("%se\n\n", ft_strrchr(a, e));
	printf("%sf\n\n", ft_strrchr(a, f));
	printf("%sg\n\n", ft_strrchr(a, g));
	printf("%si\n\n", ft_strrchr(a, i));

	return (0);
}*/
