/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:50:41 by chanin            #+#    #+#             */
/*   Updated: 2025/03/26 22:50:45 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (size <= i)
		return (size + ft_strlen(src));
	while (src && src[j] && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*if (ft_strlen(src) + ft_strlen(dst) < size)
		return (ft_strlen(src) + ft_strlen(dst));
	else
		return (ft_strlen(src) + size);*/
	//return (ft_strlen(dst));
	/*if (ft_strlen(dst) + ft_strlen(src) >= size)
		return (ft_strlen(dst) + ft_strlen(src));
	else
		return (size);*/

/*int	main(void)
{
	char *a = "abc";
	char b[20] = "def";
	char c[40] = "ghi";
	char d[100] = "jkl";

	printf("%zu\n\n", ft_strlcat(b, a, 2));
	printf("%s\n\n", b);
	printf("%zu\n\n", ft_strlcat(c, a, 2));
	printf("%s\n\n", c);
	printf("%zu\n\n", ft_strlcat(d, a, 2));
	printf("%s\n\n", d);
	printf("%zu\n\n", ft_strlcat(c, b, 2));
	printf("%s\n\n", c);
	printf("%zu\n\n", ft_strlcat(d, b, 2));
	printf("%s\n\n", d);
	printf("%zu\n\n", ft_strlcat(d, c, 100));
	printf("%s\n\n", d);
	return (0);
}*/

/*size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size < ft_strlen(dst))
	{
		while (i < size && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		while (i < size - 1 && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
			if (src[i] == 0)
			{
				while (i < size)
				{
					dst[i] = '\0';
					i++;
				}
			}
		}
	}
	return (ft_strlen(dst));
}*/
