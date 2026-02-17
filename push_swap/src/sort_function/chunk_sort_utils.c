/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 10:40:50 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/21 11:26:05 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	get_position(t_list *stack, int val)
{
	t_list	*current;
	int		pos;

	current = stack;
	pos = 0;
	while (current)
	{
		if (current->index == val)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}
