/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:30:39 by almaldon          #+#    #+#             */
/*   Updated: 2025/04/24 12:30:41 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

static int	num_dgts(int n)
{
	int	n2;
	int	count;

	count = 0;
	n2 = n;
	if (n < 0)
		n2 = -n;
	if (n == 0)
		return (1);
	while (n2 >= 1)
	{
		count++;
		n2 = n2 / 10;
	}
	return (count);
}

static char	*ft_itoa_neg(int n)
{
	int		size;
	int		i;
	char	*num;

	i = 1;
	size = num_dgts(n);
	num = malloc((size + 2) * sizeof(char));
	if (!num)
		return (0);
	num[0] = '-';
	while (size > 0)
	{
		num[i] = (n / ft_recursive_power(10, size - 1)) + '0';
		n = n % ft_recursive_power(10, size - 1);
		i++;
		size--;
	}
	num[i] = '\0';
	return (num);
}

static char	*min_int(void)
{
	char	*num;

	num = malloc(12 * sizeof(char));
	if (!num)
		return (0);
	num[0] = '-';
	num[1] = '2';
	num[2] = '1';
	num[3] = '4';
	num[4] = '7';
	num[5] = '4';
	num[6] = '8';
	num[7] = '3';
	num[8] = '6';
	num[9] = '4';
	num[10] = '8';
	num[11] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	char	*num;

	if (n == -2147483648)
	{
		return (min_int());
	}
	i = 0;
	size = num_dgts(n);
	if (n < 0)
		return (ft_itoa_neg(-n));
	num = malloc((size + 1) * sizeof(char));
	if (!num)
		return (0);
	while (size > 0)
	{
		num[i] = (n / ft_recursive_power(10, size - 1)) + '0';
		n = n % ft_recursive_power(10, size - 1);
		i++;
		size--;
	}
	num[i] = '\0';
	return (num);
}
