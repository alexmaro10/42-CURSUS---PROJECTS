/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:09:31 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/25 09:02:03 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_str(va_list args, int i)
{
	char	*s;
	int		j;

	if (i)
		j = -1;
	j = -1;
	s = va_arg(args, char *);
	if (s)
	{
		while (s[++j])
			write(1, &s[j], 1);
		return (j);
	}
	write(1, "(null)", 6);
	return (6);
}
