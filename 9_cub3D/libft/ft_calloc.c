/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:55:24 by chanin            #+#    #+#             */
/*   Updated: 2025/03/28 13:55:26 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*a;

	i = 0;
	if (nmemb * size > 2147483647)
		return (NULL);
	a = malloc(nmemb * size);
	if (!a)
		return (NULL);
	while (i < nmemb * size)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}

/*if (nmemb == 0 || size == 0)
		return malloc(0);*/

/*int	main(void)
{
	size_t nmemb = 2;
	size_t size = 3;
	size_t i = 0;
	char	*b = ft_calloc(nmemb, size);
	
	if (b)
	{
        	while( i < nmemb * size)
		{
		    printf("%d ", b[i]);
		    i++;
		}
        	free(b);
	}
	else 
	{
	        printf("Error en la asignación de memoria.\n");
	}
	return(0);
}*/
