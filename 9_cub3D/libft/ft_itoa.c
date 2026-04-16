/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:45:12 by chanin            #+#    #+#             */
/*   Updated: 2025/09/17 11:21:37 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev_int_tab(char *tab, int size)
{
	int	b;
	int	c;
	int	d;

	c = size;
	d = 1;
	while (c != d && c > size / 2)
	{
		b = tab[size - c];
		tab[size - c] = tab[size - d];
		tab[size - d] = b;
		c--;
		d++;
	}
}

static int	count_digit(long int n)
{
	int	a;

	a = 0;
	if (n < 0)
	{
		n = n * -1;
		a++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		a++;
	}
	return (a);
}

static char	sign_n(int n)
{
	char	b;

	b = '+';
	if (n < 0)
		b = '-';
	return (b);
}

static char	*if_0(long int n1, char *array)
{
	if (n1 == 0)
	{
		array[0] = '0';
		array[1] = '\0';
	}
	return (array);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*array;
	long int	n1;

	i = 0;
	n1 = n;
	array = ft_calloc(count_digit(n) + 1, sizeof (char));
	if (!array)
		return (NULL);
	if (n1 == 0)
		return (if_0(n1, array));
	if (sign_n(n) == '-')
		n1 = n1 * -1;
	while (n1 > 0)
	{
		array[i] = (n1 % 10) + '0';
		n1 = n1 / 10;
		i++;
	}
	if (sign_n(n) == '-')
		array[i++] = '-';
	ft_rev_int_tab(array, ft_strlen(array));
	array[i] = '\0';
	return (array);
}

/*int	main(void)
{
	int	n = -2147483648;
	char	*t = ft_itoa(n);
	
	printf("%s", t);
	free(t);
	return (0);
}*/
