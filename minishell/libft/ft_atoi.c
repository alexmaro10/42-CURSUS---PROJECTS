/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:45:12 by chanin            #+#    #+#             */
/*   Updated: 2025/04/03 13:45:14 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/*if (nptr[i] == '\e')
	return (0);*/

/*int main(void)
{
	printf("%d\n",atoi("  -+-9"));
	printf("%d\n",ft_atoi("  -+-9"));
	return(0);
}*/

/*int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (nptr[i] == '\e')
		return (0);
	while (ft_isprint(nptr[i]) == 0)
		i++;
	while (nptr[i] == ' ')
		i++;
	while (ft_isprint(nptr[i]) == 0)
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}*/

/*int	main(void)
{
	printf("%d\n\n", ft_atoi("\e-1234"));
	printf("%d\n\n", ft_atoi("+9987wer8"));
	printf("%d\n\n", ft_atoi("-1"));
	printf("%d\n\n", ft_atoi("  -+9987"));
	printf("%d\n\n", ft_atoi("1"));
	printf("%d\n\n", ft_atoi("  -a1"));
	return (0);
}*/

/*int ft_atoi(char *nptr)
{
	int i = 0;
	int result = 0;
	int sign = 1;

	while (nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}*/

/*int	sign(char *nptr)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (nptr[i] == ' ' || nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			c++;
		i++;
	}
	if (c % 2 == 1)
		return (1);
	return (0);
}

int	ft_atoi(char *nptr)
{
	int		n;
	int		i;
	char	a;

	i = 0;
	n = 0;
	while (nptr[i] < '0' || nptr[i] > '9')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		a = nptr[i];
		n *= 10;
		n += a - '0';
		i++;
	}
	if (sign(nptr) == 1)
		n = n * -1;
	return (n);
}*/
