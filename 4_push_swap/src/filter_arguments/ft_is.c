/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:18:40 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/21 10:41:44 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	isdgt(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\f'
		|| c == '\r' || c == '\n' || c == '\v')
		return (1);
	return (0);
}

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	int	resp;

	resp = 1024;
	if (c < 'A')
	{
		resp = 0;
	}
	else if (c > 'Z' && c < 'a')
	{
		resp = 0;
	}
	else if (c > 'z')
	{
		resp = 0;
	}
	return (resp);
}

int	is_sorted(t_list *lst)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = lst;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		while (ptr2)
		{
			if (ft_strcmp(ptr2->value, ptr1->value) < 0)
				return (0);
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return (1);
}
