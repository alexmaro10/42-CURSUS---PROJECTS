/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:05:46 by almaldon          #+#    #+#             */
/*   Updated: 2025/05/16 12:05:34 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_base_minn(unsigned long nbr, unsigned long len_base, char *base)
{
	if (nbr >= len_base)
	{
		ft_base_minn(nbr / len_base, len_base, base);
		ft_base_minn(nbr % len_base, len_base, base);
	}
	else
		ft_putchar(base[nbr]);
}

int	ft_putnbr_base(long nbr, char *base, int len)
{
	len++;
	if (nbr == -2147483648)
	{
		len++;
		ft_putchar('-');
		ft_base_minn(2147483648, 16, base);
	}
	else
	{
		if (nbr < 0)
		{
			len++;
			ft_putchar('-');
			nbr = nbr * (-1);
		}
		if (nbr >= 16)
		{
			len = ft_putnbr_base(nbr / 16, base, len);
			ft_putnbr_base(nbr % 16, base, len);
		}
		if (nbr < 16)
			ft_putchar(base[nbr]);
	}
	return (len);
}
