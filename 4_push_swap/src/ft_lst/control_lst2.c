/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_lst2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 10:38:22 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/22 10:27:15 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != 0)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	assig_sort_index(t_list *lst)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		idx;

	ptr1 = lst;
	while (ptr1)
	{
		idx = 1;
		ptr2 = lst;
		while (ptr2)
		{
			if (ft_strcmp(ptr2->value, ptr1->value) < 0)
				idx++;
			ptr2 = ptr2->next;
		}
		ptr1->index = idx;
		ptr1 = ptr1->next;
	}
}
