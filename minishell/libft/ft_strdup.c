/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:55:24 by chanin            #+#    #+#             */
/*   Updated: 2025/03/28 13:55:26 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned long	i;
	char			*a;

	i = 0;
	a = malloc((ft_strlen(s) + 1) * sizeof (char));
	if (!a)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = s[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

/*int	main(void)
{
	unsigned long	i;
	char	*s = "hello";
	char	*t = ft_strdup(s);
	
	i = 0;
	if (t) 
	{
        	while( i < ft_strlen(s)* sizeof (char))
		{
		    printf("%c ", t[i]);
		    i++;
		}
        	free(t);
	}
	else 
	{
	        printf("Error en la asignación de memoria.\n");
	}
	return(0);
}*/

/*	size_t	i;
	char	*a;
	
	i = 0;
	a = malloc(nmemb * size);
	if (!a)
		return NULL;
	while (i < nmemb * size)
	{
		a[i] = 0;
		i++;
	}
	return(a);*/

/*int	main(void)
{
	size_t nmemb = 2;
	size_t size = 3;
	size_t i = 0;
	char	*a = ft_calloc(nmemb, size);
	
	if (a) 
	{
        	while( i < nmemb * size)
		{
		    printf("%d ", a[i]);
		    i++;
		}
        	free(a);
	}
	else 
	{
	        printf("Error en la asignación de memoria.\n");
	}
	return(0);
}*/
