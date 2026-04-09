/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 22:33:49 by chanin            #+#    #+#             */
/*   Updated: 2025/06/12 13:08:43 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthex_upper(unsigned int n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex_upper(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_putvoid_recursive(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_putvoid_recursive(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_putvoid(void *ptr)
{
	int				count;
	char			*hex;
	unsigned long	n;

	count = 0;
	hex = "0123456789abcdef";
	n = (unsigned long)ptr;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	if (n >= 16)
		count += ft_putvoid_recursive(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_process_string(const char string, va_list args)
{
	int	count;

	count = 0;
	if (string == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (string == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (string == 'p')
		count = ft_putvoid(va_arg(args, void *));
	else if (string == 'd' || string == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (string == 'u')
		count = ft_putunbr(va_arg(args, unsigned int));
	else if (string == 'x')
		count = ft_puthex_lower(va_arg(args, unsigned int));
	else if (string == 'X')
		count = ft_puthex_upper(va_arg(args, unsigned int));
	else if (string == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *string, ...)
{
	int		count;
	int		i;
	va_list	args;

	if (!string)
		return (-1);
	count = 0;
	i = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%' && string[i + 1])
		{
			i++;
			count += ft_process_string(string[i], args);
		}
		else if (string[i] != '%')
			count += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{	
	char	c = 'c';
	char	*s = "hola";
	int	i = -10;
	unsigned	u = 10;
	void	*v = "hola";
	
	ft_printf("char %c\n", c);
	printf("char %c\n", c);
	write(1, "\n", 1);
	ft_printf("string %s\n", s);
	printf("string %s\n", s);
	write(1, "\n", 1);
	ft_printf("int %i\n", i);
	printf("int %i\n", i);
	write(1, "\n", 1);
	ft_printf("uint %u\n", u);
	printf("uint %u\n", u);
	write(1, "\n", 1);
	ft_printf("hex %x\n", u);
	printf("hex %x\n", u);
	write(1, "\n", 1);
	ft_printf("HEX %X\n", u);
	printf("HEX %X\n", u);
	write(1, "\n", 1);
	ft_printf("void %p\n", v);
	printf("void %p\n", v);
	write(1, "\n", 1);
	ft_printf("%%\n");
	printf("%%\n");
	write(1, "\n", 1);
	return (0);
}*/
