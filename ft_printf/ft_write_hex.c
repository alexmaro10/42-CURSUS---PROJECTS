/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:10:10 by almaldon          #+#    #+#             */
/*   Updated: 2025/05/15 08:48:40 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex(va_list args, int i, char c)
{
	long		n;

	n = i;
	n = va_arg(args, int);
	if (n < 0)
		n = n + 4294967296;
	if (c == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef", 0));
	else
		return (ft_putnbr_base(n, "0123456789ABCDEF", 0));
}
