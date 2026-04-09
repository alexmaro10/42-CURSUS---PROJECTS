/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 08:45:35 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/22 11:46:35 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

static int	find_position_in_chunk(t_list *lst_a, int min, int max)
{
	t_list	*current;
	int		pos;

	pos = 0;
	current = lst_a;
	while (current)
	{
		if (current->index >= min && current->index <= max)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

static int	find_max(t_list *stack)
{
	t_list	*current;
	int		max;

	if (ft_lstsize(stack) == 0)
		return (-1);
	current = stack;
	max = current->index;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

static void	pb_chunk(t_list **lst_a, t_list **lst_b, int cnk_min, int cnk_max)
{
	int	pos;

	pos = find_position_in_chunk(*lst_a, cnk_min, cnk_max);
	while (pos != -1)
	{
		if (pos <= ft_lstsize(*lst_a) / 2)
		{
			while (pos-- > 0)
				rotate_a(lst_a);
		}
		else
		{
			pos = ft_lstsize(*lst_a) - pos;
			while (pos-- > 0)
				r_rotate_a(lst_a);
		}
		push_b(lst_a, lst_b);
		if ((*lst_b)->index < (cnk_min + cnk_max) / 2)
			rotate_b(lst_b);
		pos = find_position_in_chunk(*lst_a, cnk_min, cnk_max);
	}
}

static void	push_back_to_a(t_list **lst_a, t_list **lst_b)
{
	int	max;
	int	pos;

	while (ft_lstsize(*lst_b) > 0)
	{
		max = find_max(*lst_b);
		pos = get_position(*lst_b, max);
		if (pos <= ft_lstsize(*lst_b) / 2)
		{
			while (pos-- > 0)
				rotate_b(lst_b);
		}
		else
		{
			pos = ft_lstsize(*lst_b) - pos;
			while (pos-- > 0)
				r_rotate_b(lst_b);
		}
		push_a(lst_a, lst_b);
	}
}

void	chunk_sort(t_list **lst_a, t_list **lst_b, int total_elements)
{
	int	num_chunks;
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	i;

	i = -1;
	num_chunks = 5;
	if (total_elements >= 500)
		num_chunks = 10;
	chunk_size = total_elements / num_chunks;
	while (++i < num_chunks)
	{
		chunk_min = i * chunk_size;
		chunk_max = (i + 1) * chunk_size - 1;
		if (i == num_chunks - 1)
			chunk_max = total_elements - 1;
		pb_chunk(lst_a, lst_b, chunk_min, chunk_max);
	}
	push_back_to_a(lst_a, lst_b);
}
