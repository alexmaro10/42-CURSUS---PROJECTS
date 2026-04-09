/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:34:15 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/21 10:23:58 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

static void	rotate_cw(t_list **head)
{
	t_list	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
}

void	rotate_a(t_list **head)
{
	rotate_cw(head);
	write (1, "ra\n", 3);
}

void	rotate_b(t_list **head)
{
	rotate_cw(head);
	write (1, "rb\n", 3);
}

void	rotate_ab(t_list **list_a, t_list **list_b)
{
	rotate_cw(list_a);
	rotate_cw(list_b);
	write(1, "rr\n", 3);
}
