/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:06:17 by chanin            #+#    #+#             */
/*   Updated: 2025/04/21 16:06:19 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*t;

	i = 0;
	t = (char *)s;
	while (i < n)
	{
		t[i] = c;
		i++;
	}
	s = (void *)t;
	return (s);
}

/*printf("\n0x%" PRIXPTR "\n", (uintptr_t) &t);
	printf("\n0x%" PRIXPTR "\n", (uintptr_t) &s);
	printf("%s\n", t);
	printf("%s\n", (char *)s);*/

/*int	main(void)
{
	char s[] = "hola";
	int c = 'x';
	size_t n = 2;
	ft_memset(s, c, n);
}*/
