/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:36:54 by almaldon          #+#    #+#             */
/*   Updated: 2025/07/21 08:59:49 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

static int	ft_error(void)
{
	write (2, "Error\n", 6);
	return (0);
}

static void	sort(t_list **lst_a, t_list **lst_b, int size)
{
	if (size == 2)
		sort_2_arg(lst_a);
	else if (size == 3)
		sort_3_arg(lst_a);
	else if (size == 4)
		sort_4_arg(lst_a, lst_b);
	else if (size == 5)
		sort_5_arg(lst_a, lst_b);
	else if (size > 5 && size < 500)
		chunk_sort(lst_a, lst_b, size);
	else
		chunk_sort(lst_a, lst_b, size);
}

static int	control_arguments(char **argv, char **nbrs)
{
	if (control_total(argv, nbrs) != 1)
	{
		return (0);
	}
	return (1);
}

void	push_swap(char **nbrs)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		size;
	int		i;

	i = -1;
	lst_a = NULL;
	lst_b = NULL;
	while (nbrs[++i] != NULL)
		ft_lstadd_back(&lst_a, ft_lstnew(nbrs[i]));
	if (is_sorted(lst_a))
		return (free_lst(&lst_a));
	assig_sort_index(lst_a);
	size = ft_lstsize(lst_a);
	sort(&lst_a, &lst_b, size);
	free_lst(&lst_a);
}

int	main(int argc, char **argv)
{
	char	**nbrs;
	int		i;

	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			if (ft_strlen(argv[i]) == 0)
				return (ft_error());
		}
		nbrs = ft_split_multiple(&argv[1], argc - 1, ' ');
		if (!nbrs[0])
			write (2, "Error\n", 6);
		if (control_arguments(argv, nbrs) != 1)
		{
			write(2, "Error\n", 6);
			free_nbrs(nbrs);
			return (0);
		}
		push_swap(nbrs);
		free_nbrs(nbrs);
	}
	return (0);
}
