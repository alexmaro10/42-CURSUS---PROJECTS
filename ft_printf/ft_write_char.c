/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:09:21 by almaldon          #+#    #+#             */
/*   Updated: 2025/05/15 09:49:48 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(va_list args, int i)
{
	char	c;

	if (i)
	{
		c = va_arg(args, int);
		write(1, &c, 1);
	}
	return (1);
}
