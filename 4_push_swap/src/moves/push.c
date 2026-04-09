/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:34:03 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/21 10:20:01 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

static void	push(t_list **list_from, t_list **list_to)
{
	t_list	*tmp;

	if (list_from == NULL || *list_from == NULL)
		return ;
	tmp = *list_from;
	*list_from = (*list_from)->next;
	if (list_to == NULL)
		*list_to = tmp;
	else
	{
		tmp->next = *list_to;
		*list_to = tmp;
	}
}

void	push_a(t_list **list_a, t_list **list_b)
{
	push(list_b, list_a);
	write(1, "pa\n", 3);
}

void	push_b(t_list **list_a, t_list **list_b)
{
	push(list_a, list_b);
	write(1, "pb\n", 3);
}
