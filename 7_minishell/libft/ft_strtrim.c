/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:39:44 by chanin            #+#    #+#             */
/*   Updated: 2025/08/10 13:17:17 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/* Creates a new string */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*s3;

	end = ft_strlen(s1) - 1;
	start = 0;
	i = 0;
	if (!*s1 && !*set)
		return (ft_strdup(""));
	if (!*set)
		return (ft_strdup(s1));
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	while (end >= start && ft_is_in_set(s1[end], set))
		end--;
	s3 = malloc((end - start + 2) * sizeof(char));
	if (!s3)
		return (NULL);
	while (start <= end)
		s3[i++] = s1[start++];
	s3[i] = '\0';
	return (s3);
}

/*int main()
{
	char *s = " hola ";
	s = ft_strtrim(s, " ");
	printf("%s\n", s);
	free(s);
	return 0;
}*/

/*char *ft_strtrim(char const *s1, char const *set)
{
	int start = 0;
	int i = 0;
	int end;
	char *trimmed;

    end = ft_strlen(s1) - 1;
    
    if (!s1 || !set)
	return NULL;
	
    if (*s1 == '\0')
    {
	trimmed = (char *)malloc(1);
	if (!trimmed)
	    return NULL;
	trimmed[0] = '\0';
	return trimmed;
    }
    
    if (*set == '\0')
    {
	trimmed = ft_strdup(s1);
	return trimmed;
    }
    
    while (s1[start] && ft_is_in_set(s1[start], set))
	start++;
	
    if (s1[start] == '\0')
    {
	trimmed = (char *)malloc(1);
	if (!trimmed)
	    return NULL;
	trimmed[0] = '\0';
	return trimmed;
    }
    
    while (end >= start && ft_is_in_set(s1[end], set))
	end--;
    trimmed = (char *)malloc(end - start + 2);
    if (!trimmed)
	return NULL;
    while (start <= end)
    {
	trimmed[i] = s1[start];
	i++;
	start++;
    }

    return trimmed;
}*/

/*int main(void)
{
	unsigned long	i;
	char const *s1 = "abcdef"; 
	char const *set = "fcae";
	char	*t = ft_strtrim(s1, set);
	
	i = 0;
	if (t) 
	{
        	while( i < (ft_strlen(t) + 1)* sizeof (char))
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

/*char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_set;
	int		len_s1;
	int		a;
	int		a2;
	int		a3;
	int		b;
	int		c;
	char	*s3;

	len_s1 = ft_strlen(s1);
	len_set = ft_strlen(set);
	a = 0;
	a2 = 0;
	a3 = 0;
	b = len_s1 - 1;
	c = 0;
	while (b >= 0)
	{
		while(set[c])
		{
			if(s1[b] == set[c])
			{
				a3++;
				a++;
			}
			c++;
		}
		c = 0;
		b--;
	}
	while (b <= len_s1 - 1)
	{
		while(set[c])
		{
			if(s1[b] == set[c])
			{
				a2++;
				a++;
			}
			c++;
		}
		b++;
	}
	s3 = malloc((a + 1) * sizeof (char));
	if (!s3)
		return (NULL);
		
	s3 = ft_substr(s1, a2, a);*/
	/*while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}*/
	/*s3[len_s1] = '\0';
	return (s3);
}*/

/*char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_set;
	int		len_s1;
	int		a;
	int		b;
	int		c;
	char	*s3;

	len_s1 = ft_strlen(s1);
	len_set = ft_strlen(set);
	a = 0;
	b = len_s1 - 1;
	c = 0;
	while (b >= 0)
	{
		while(set[c])
		{
			if(s1[b] == set[c])
				a++;
			c++;
		}
		c = 0;
		b--;
	}
	while (b <= len_s1 - 1)
	{
		while(set[c])
		{
			if(s1[b] == set[c])
				a++;
			c++;
		}
		b++;
	}
	s3 = malloc((a + 1) * sizeof (char));
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
}*/
