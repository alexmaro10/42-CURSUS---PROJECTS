/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:06:17 by chanin            #+#    #+#             */
/*   Updated: 2025/04/21 16:06:19 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*t;

	i = 0;
	t = (char *)s;
	while (i < n)
	{
		t[i] = '\0';
		i++;
	}
}

/*int main(void)
{
	char s[] = "hola";
	unsigned int n = 2;
	ft_bzero(s, n);
	printf("%c\n\n", s[3]);
}*/
