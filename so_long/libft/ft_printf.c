/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:27:30 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/25 09:02:03 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	format(va_list args, const char *str, int *i)
{
	if (str[*i + 1] == 'c')
		return (ft_write_char(args, ++(*i)));
	else if (str[*i + 1] == 's')
		return (ft_write_str(args, ++(*i)));
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		return (ft_write_number(args, ++(*i)));
	else if (str[*i + 1] == 'u')
		return (ft_write_unsigned_nbr(args, (*i)++));
	else if (str[*i + 1] == 'p')
		return (ft_write_ptr(args, ++(*i)));
	else if (str[*i + 1] == 'x' || str[*i + 1] == 'X')
	{
		(*i)++;
		return (ft_write_hex(args, *i, str[*i]));
	}
	else if (str[*i + 1] == '%')
	{
		write(1, "%", 1);
		(*i)++;
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = -1;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
			len += format(args, str, &i);
		else
		{
			write(1, &str[i], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
