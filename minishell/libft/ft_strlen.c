/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:50:41 by chanin            #+#    #+#             */
/*   Updated: 2025/03/26 22:50:45 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

/*int	main(void)
{
	char	a[] = "hola";

	printf ("%zu", ft_strlen(&a[0]));
	return (0);
}*/

/*int	ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		j++;
		i++;
	}
	return (j);
}*/

//printf ("%d", j);
//printf ("\n%d", j);
/*int	main(void)
{
	char	a[] = "Hellop";

	ft_strlen(&a[0]);
	return (0);
}*/
