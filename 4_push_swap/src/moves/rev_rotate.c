/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:34:21 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/21 10:23:27 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

static void	rotate_ccw(t_list **head)
{
	t_list	*prev_tail;
	t_list	*new_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	prev_tail = *head;
	while (prev_tail->next != NULL)
	{
		new_tail = prev_tail;
		prev_tail = prev_tail->next;
	}
	prev_tail->next = *head;
	new_tail->next = NULL;
	*head = prev_tail;
}

void	r_rotate_a(t_list **head)
{
	rotate_ccw(head);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_list **head)
{
	rotate_ccw(head);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_list **list_a, t_list **list_b)
{
	rotate_ccw(list_a);
	rotate_ccw(list_b);
	write(1, "rrr\n", 4);
}
