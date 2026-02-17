/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 10:46:09 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/20 16:37:24 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	sort_2_arg(t_list **lst)
{
	char	*nbr1;
	char	*nbr2;

	nbr1 = (*lst)->value;
	nbr2 = (*lst)->next->value;
	if (ft_strcmp(nbr2, nbr1) < 0)
	{
		swap_a(lst);
	}
}

void	sort_3_arg(t_list **lst)
{
	t_list	*nbr1;
	t_list	*nbr2;
	t_list	*nbr3;

	assig_sort_index(*lst);
	nbr1 = (*lst);
	nbr2 = (*lst)->next;
	nbr3 = (*lst)->next->next;
	if (nbr1->index == 1 && nbr2->index == 3 && nbr3->index == 2)
	{
		r_rotate_a(lst);
		swap_a(lst);
	}
	else if (nbr1->index == 2 && nbr2->index == 1 && nbr3->index == 3)
		swap_a(lst);
	else if (nbr1->index == 2 && nbr2->index == 3 && nbr3->index == 1)
		r_rotate_a(lst);
	else if (nbr1->index == 3 && nbr2->index == 1 && nbr3->index == 2)
		rotate_a(lst);
	else if (nbr1->index == 3 && nbr2->index == 2 && nbr3->index == 1)
	{
		rotate_a(lst);
		swap_a(lst);
	}
}

void	sort_4_arg(t_list **lst_a, t_list **lst_b)
{
	int	nbr[4];

	assig_sort_index(*lst_a);
	nbr[0] = (*lst_a)->index;
	nbr[1] = (*lst_a)->next->index;
	nbr[2] = (*lst_a)->next->next->index;
	nbr[3] = (*lst_a)->next->next->next->index;
	if (nbr[1] == 1)
		swap_a(lst_a);
	else if (nbr[2] == 1)
	{
		r_rotate_a(lst_a);
		r_rotate_a(lst_a);
	}
	else if (nbr[3] == 1)
		r_rotate_a(lst_a);
	push_b(lst_a, lst_b);
	sort_3_arg(lst_a);
	push_a(lst_a, lst_b);
}

void	sort_5_arg(t_list **lst_a, t_list **lst_b)
{
	int	nbr[5];

	nbr[0] = (*lst_a)->index;
	nbr[1] = (*lst_a)->next->index;
	nbr[2] = (*lst_a)->next->next->index;
	nbr[3] = (*lst_a)->next->next->next->index;
	nbr[4] = (*lst_a)->next->next->next->next->index;
	if (nbr[1] == 1)
		swap_a(lst_a);
	else if (nbr[2] == 1)
	{
		rotate_a(lst_a);
		swap_a(lst_a);
	}
	else if (nbr[3] == 1)
	{
		r_rotate_a(lst_a);
		r_rotate_a(lst_a);
	}
	else if (nbr[4] == 1)
		r_rotate_a(lst_a);
	push_b(lst_a, lst_b);
	sort_4_arg(lst_a, lst_b);
	push_a(lst_a, lst_b);
}
