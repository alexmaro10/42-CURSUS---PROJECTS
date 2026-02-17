/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:21:10 by almaldon          #+#    #+#             */
/*   Updated: 2025/05/16 12:04:43 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <limits.h>

int		ft_printf(char const *str, ...);
int		ft_write_char(va_list args, int i);
int		ft_write_str(va_list args, int i);
int		ft_write_number(va_list args, int i);
int		ft_write_unsigned_nbr(va_list args, int i);
int		ft_write_hex(va_list args, int i, char c);
int		ft_write_ptr(va_list args, int i);
int		ft_putnbr(long n, int len);
int		ft_putnbr_base(long nbr, char *base, int len);

#endif