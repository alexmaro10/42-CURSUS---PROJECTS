/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:08:59 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/25 09:02:03 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftp_putnbr(long n, int len)
{
	char			c;

	len++;
	if (n < 0)
	{
		len++;
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		len = ftp_putnbr(n / 10, len);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (len);
}

int	ft_write_number(va_list args, int i)
{
	int	n;
	int	len;

	if (i)
		len = 0;
	len = 0;
	n = va_arg(args, int);
	return (ftp_putnbr(n, len));
}
