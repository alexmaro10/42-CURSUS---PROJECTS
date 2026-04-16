/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:30:12 by chanin            #+#    #+#             */
/*   Updated: 2025/04/01 19:01:12 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*m;
	unsigned char	*l;

	i = 0;
	m = (unsigned char *)src;
	l = (unsigned char *)dest;
	if (n == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		l[i] = m[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	a[] = "Hella";
	char	b[6] = "";
	char	b2[4] = "";

	//printf("%s\n", ft_memcpy(b2, a, 3));
	ft_memcpy(&b[0], &a[0], 3);
	printf("%s\n\n", b);
	memcpy(&b2[0], &a[0], 3);
	printf("%s\n\n", b2);
	return (0);
}*/

/*char	*ft_memcpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}*/
