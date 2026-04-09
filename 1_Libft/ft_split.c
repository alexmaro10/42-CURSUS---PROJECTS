/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:29:43 by almaldon          #+#    #+#             */
/*   Updated: 2025/04/25 12:29:45 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (ft_strlen(s + i))
		words = 1;
	else
		words = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			words++;
		i++;
	}
	return (words);
}

static int	len_word(char const *s, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static int	fill_word(char *word, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	j = 0;
	while (s[i] && s[i] != c)
		word[j++] = s[i++];
	word[j] = '\0';
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static void	w_free(char **array, int i)
{
	while (--i >= 0)
		free(array[i]);
	free(array);
}

char	**ft_split(char const *s, char c)
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
