/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:38:12 by almaldon          #+#    #+#             */
/*   Updated: 2025/05/15 08:46:54 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_unsigned_nbr(va_list args, int i)
{
	long	num;
	int		len;

	if (i)
		len = 0;
	len = 0;
	num = va_arg(args, int);
	if (num < 0)
		num = num + 4294967296;
	return (ft_putnbr(num, len));
}
