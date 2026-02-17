/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:29:43 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/26 12:11:11 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_all(char **tab)
{
	char	**ptr;

	if (tab)
	{
		ptr = tab;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(tab);
	}
	return (NULL);
}

static int	ft_allocate(char **tab, char const *s, char sep)
{
	char const	*tmp;

	while (*s)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*tab = ft_substr(s, 0, tmp - s);
			if (!*tab)
				return (0);
			s = tmp;
			++tab;
		}
	}
	*tab = NULL;
	return (1);
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	if (!ft_allocate(new, s, c))
		return (ft_free_all(new));
	return (new);
}
