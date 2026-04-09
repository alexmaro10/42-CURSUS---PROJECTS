/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 08:38:37 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/21 09:58:44 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

static int	control_1(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j]))
				return (0);
			if (!isdgt(argv[i][j]) && !ft_isspace(argv[i][j]))
			{
				if (ft_issign(argv[i][j]) && !isdgt(argv[i][j + 1]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	control_2(char **nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (ft_strcmp(nbrs[i], nbrs[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	control_3(char **nbrs)
{
	int		i;

	i = -1;
	while (nbrs[++i])
	{
		if (ft_strcmp(nbrs[i], "2147483647") > 0
			|| ft_strcmp(nbrs[i], "-2147483648") < 0)
			return (0);
	}
	return (1);
}

static int	control_4(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_issign(argv[i][j]))
				if (argv[i][j - 1] && !ft_isspace(argv[i][j - 1]))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	control_total(char **argv, char **nbrs)
{
	if (!control_1(argv))
		return (0);
	if (!control_4(argv))
		return (0);
	if (!control_2(nbrs))
		return (0);
	if (!control_3(nbrs))
		return (0);
	return (1);
}
