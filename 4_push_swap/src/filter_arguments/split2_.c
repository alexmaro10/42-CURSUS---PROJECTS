/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:05:49 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/21 10:18:07 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

static void	w_free(char **array, int arr_i)
{
	while (--arr_i >= 0)
		free(array[arr_i]);
	free(array);
}

// Split individual string
static char	**ft_split(char *s, char c)
{
	char	**array;
	int		i_len[2];

	array = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (s && array)
	{
		i_len[0] = 0;
		if (count_words(s, c))
		{
			while (*s)
			{
				i_len[1] = len_word(s, c) + 1;
				array[i_len[0]] = malloc(i_len[1]);
				if ((array[i_len[0]]))
					s += fill_word(array[i_len[0]++], s, c);
				else
				{
					w_free(array, i_len[0]);
					return (NULL);
				}
			}
		}
		array[i_len[0]] = NULL;
	}
	return (array);
}

// Split varios strings
char	**ft_split_multiple(char **args, int argc, char c)
{
	char	**temp;
	char	**result;
	int		i_j_k_total[4];

	i_j_k_total[3] = 0;
	i_j_k_total[0] = 0;
	while (i_j_k_total[0] < argc)
		i_j_k_total[3] += count_words(args[i_j_k_total[0]++], c);
	result = malloc(sizeof(char *) * (i_j_k_total[3] + 1));
	if (!result)
		return (NULL);
	i_j_k_total[0] = 0;
	i_j_k_total[2] = 0;
	while (i_j_k_total[0] < argc)
	{
		temp = ft_split(args[i_j_k_total[0]++], c);
		if (!temp)
			return (w_free(result, i_j_k_total[2]), NULL);
		i_j_k_total[1] = 0;
		while (temp[i_j_k_total[1]])
			result[i_j_k_total[2]++] = temp[i_j_k_total[1]++];
		free(temp);
	}
	result[i_j_k_total[2]] = NULL;
	return (result);
}

void	free_nbrs(char **nbrs)
{
	int		i;

	i = -1;
	while (nbrs && nbrs[++i])
	{
		free(nbrs[i]);
	}
	free(nbrs);
}
