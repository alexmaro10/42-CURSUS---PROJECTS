/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:39:44 by chanin            #+#    #+#             */
/*   Updated: 2025/04/02 10:39:47 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!s3)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

/*int main(void)
{
	unsigned long	i;
	char const *s1 = ""; 
	char const *s2 = " world";
	char	*t = ft_strjoin(s1, s2);;
	
	i = 0;
	if (t) 
	{
        	while( i < (ft_strlen(s1) + ft_strlen(s2) + 1)* sizeof (char))
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
