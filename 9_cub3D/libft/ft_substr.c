/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:45:12 by chanin            #+#    #+#             */
/*   Updated: 2025/04/03 13:45:14 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*a;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	a = malloc((len + 1) * sizeof (char));
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = s[start];
		start++;
		i++;
	}
	a[i] = '\0';
	return (a);
}

/*int main(void)
{
	unsigned long	i;
	char const *s = "hello"; 
	unsigned int start = 1; 
	size_t len = 3;
	char	*t = ft_substr(s, start, len);
	
	i = 0;
	if (t) 
	{
        	while( i < ft_strlen(s)* sizeof (char))
		{
		    printf("%c", t[i]);
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

/*char	*ft_strdup(const char *s)
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
}*/

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
