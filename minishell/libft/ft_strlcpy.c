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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	else if (!(src && *src))
		dst[i] = src[i];
	else if (size < ft_strlen(dst))
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else
	{
		while (i < size - 1)
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
	return (ft_strlen(src));
}*/

/*int	main(void)
{
	char	a[5] = "Ho la";
	char	b[3] = "a";
	char	c[5] = "a";
	char	d[7] = "a";

	printf("%zu\n\n", ft_strlcpy(b, a, 3));
	printf("%s\n\n", b);
	printf("%zu\n\n", ft_strlcpy(c, a, 5));
	printf("%s\n\n", c);
	printf("%zu\n\n", ft_strlcpy(d, a, 7));
	printf("%s\n\n", d);
	return (0);
}*/
