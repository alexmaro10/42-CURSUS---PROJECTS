/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:45:12 by chanin            #+#    #+#             */
/*   Updated: 2025/04/03 13:45:14 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	j;

	j = 0;
	while (j < ft_strlen(s))
	{
		f(j, &s[j]);
		j++;
	}
}

/*void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	j;

	j = 0;
	while (j < ft_strlen(s))
	{
		f(1, s[j]);
		j++;
	}
	s[j] = '\0';
}*/

/*void	ft_test_striteri(unsigned int a, char *str)
{

	while (str && *str)
	{
		if ((*str >= 'A') && (*str <= 'Z'))
			*str = *str + a;
		str++;
	}
}

int	main(void)
{
	char s[] = "aAbB";
	
	ft_striteri(s, ft_test_striteri);
	printf("%s", s);
	return(0);
}*/

/*char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	j;
	char	*a;

	j = 0;
	a = malloc((ft_strlen(s) + 1) * sizeof (char));
	if (!a)
		return (NULL);
	while (j < ft_strlen(s))
	{
		a[j] = f(j, s[j]);
		j++;
	}
	a[j] = '\0';
	return (a);
}*/

/*char	ft_switch_char(unsigned int i, char c)
{
	i = 1;
	if (c >= 'A' && c <= 'Z')
	{
		c = c + i;
	}
	else if (c >= 'a' && c <= 'z')
	{
		c = c - i;
	}
	return (c);
}

int	main(void)
{
	char const *s = "aAbB";
	
	printf("%s", ft_strmapi(s, ft_switch_char));
	return(0);
}*/
