/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:30:12 by chanin            #+#    #+#             */
/*   Updated: 2025/04/01 19:01:12 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*t;

	s = (char *)src;
	t = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (s < t && t < s + n)
	{
		while (n--)
			t[n] = s[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			t[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*t;

	s = (char *)src;
	t = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (s < t && t < s + n)
	{
		i = n - 1;
		while (i > 0)
		{
			t[i] = s[i];
			i--;
		}
		t[i] = s[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			t[i] = s[i];
			i++;
		}
	}
	return (dest);
}*/

/*if (n == 0)
	return (dest);*/

/*int	main(void)
{
	char src[] = "abcdef";
	char src2[] = "abcdef";
	
	printf("%s\n", src);
	ft_memmove(src, src + 1, 3);
	printf("%s\n", src);
	memmove(src2, src2 + 1, 3);
	printf("%s\n", src2);
}*/

/*{
	size_t	i;
	char	*s;
	char	*t;
	
	s = (char *)src;
	t = (char *)dest;
	
	//if (ft_strlen(s) < ft_strlen(t))
	if (s < t)
	{
		i = n - 1;
		write(1, "4", 1);
		while (i > 0)
		{
			write(1, "5", 1);
			t[i] = s[i];
			i--;
		}
		t[i] = s[i];
	}
	else
	{
		i = 0;
		write(1, "2", 1);
		while (i < n)
		{
			write(1, "3", 1);
			t[i] = s[i];
			i++;
		}
	}
	return (dest);
}*/

/*char	*ft_memmove(char *dest, const char *src, int n)
{
	int	i;

	if (dest == src || n <= 0)
	{
		return (dest);
	}
	else if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			dest[i] = src[i];
			i--;
		}
	}
	return (dest);
}*/

/*int	main(void)
{	
	char	a[] = "abcdef";
	char	b[] = "abcdef";
	char	c[] = "abcdef";

	printf("%s\n", ft_memmove(&a[2], a, 2));
	printf("%s\n", ft_memmove(&b[3], b, 3));
	printf("%s\n", ft_memmove(&c[4], c, 4));

	return (0);
}*/
