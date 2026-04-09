/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:45:12 by chanin            #+#    #+#             */
/*   Updated: 2025/08/06 11:54:21 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	a;

	if (!s[0])
		return (0);
	i = 0;
	a = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			a++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (a);
}

static char	**free_array(char **s_split)
{
	size_t	i;

	i = 0;
	while (s_split[i])
	{
		free(s_split[i]);
		i++;
	}
	free(s_split);
	return (NULL);
}

static char	**make_split_2(size_t *ijstart, char const *s, char **s_split)
{
	if (ijstart[0] > ijstart[2])
	{
		s_split[ijstart[1]] = ft_substr(s, ijstart[2], ijstart[0] - ijstart[2]);
		if (!s_split[ijstart[1]])
			return (NULL);
		ijstart[1] = ijstart[1] + 1;
	}
	return (&s_split[ijstart[1]]);
}

static char	**make_split(char const *s, char c, char **s_split)
{
	size_t	ijstart[3];

	ijstart[0] = 0;
	ijstart[1] = 0;
	ijstart[2] = 0;
	while (s[ijstart[0]])
	{
		if (s[ijstart[0]] == c || s[ijstart[0]] == '\0')
		{
			if (!make_split_2(&ijstart[0], s, s_split))
				return (free_array(s_split));
			while (s[ijstart[0]] == c && s[ijstart[0]] != '\0')
				ijstart[0]++;
			ijstart[2] = ijstart[0];
		}
		else
			ijstart[0]++;
	}
	if (ijstart[0] > ijstart[2])
	{
		s_split[ijstart[1]] = ft_substr(s, ijstart[2], ijstart[0] - ijstart[2]);
		if (!s_split[ijstart[1]])
			return (free_array(s_split));
	}
	return (s_split);
}

char	**ft_split(char const *s, char c)
{
	char	**s_split;

	if (!s || !*s)
		return (NULL);
	s_split = ft_calloc((ft_word_count(s, c) + 1), sizeof (char *));
	if (!s_split)
		return (NULL);
	return (make_split(s, c, s_split));
}

/*int	main(void)
{
	int	i = 0;
	int	j = 0;
	//char const	*s = "313322223 435 33";
	//char const	*s = "12345";
	char const	*s = "";
	char 		c = '3';
	char	**t;
	
	t  = ft_split(s, c);
	if (!t)
		return (0);
	while(t[i] && *t[i])
	{
		while (t[i][j] != '\0')
		{
			write(1, &t[i][j], 1);
			j++;
		}
		write(1, "\n\n", 2);
		i++;
		j = 0;
	}
	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	return (0);
}*/

			/*if (i > start)
			{
				s_split[j] = ft_substr(s, start, i - start);
				if (!s_split[j])
					return (free_array(s_split));
				j++;
			}*/

/*char	**make_split(char const *s, char c, char **s_split)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (i > start)
			{
				s_split[j] = ft_substr(s, start, i - start);
				if (!s_split[j])
					return (free_array(s_split));
				j++;
			}
			while (s[i] == c && s[i] != '\0')
				i++;
			start = i;
		}
		else
			i++;
	}
	if (i > start)
	{
		s_split[j] = ft_substr(s, start, i - start);
		if (!s_split[j])
			return (free_array(s_split));
	}
	return (s_split);
}*/

/*static char	**ft_malloc_error(char **tab)           //SOLUTION
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_nb_words(char const *s, char c)
{
	size_t	i;
	size_t	nb_words;

	if (!s[0])
		return (0);
	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_words++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_words++;
	return (nb_words);
}

static void	ft_get_next_word(char **next_word, size_t *next_word_len, char c)
{
	size_t	i;

	*next_word += *next_word_len;
	*next_word_len = 0;
	i = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return ;
		(*next_word_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*next_word;
	size_t	next_word_len;
	size_t	i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < ft_nb_words(s, c))
	{
		ft_get_next_word(&next_word, &next_word_len, c);
		tab[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_word, next_word_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}*/

/*char	**ft_split(char const *s, char c)
{
	size_t	*array[3];
	char	**s_split;

	array[0] = 0;
	array[1] = 0;
	array[2] = 0;
	s_split = ft_calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!s_split)
		return (NULL);
	while (s[array[0]])
	{
		if (s[array[0]] == c || s[array[0]] == '\0')
		{
			if (array[0] > array[2])
				s_split[array[1]++] 
				= ft_substr(s, array[2], array[0] - array[2]);
			while (s[array[0]] == c && s[array[0]] != '\0')
				array[0]++;
			array[2] = array[0];
		}
		else
			array[0]++;
	}
	if (array[0] > array[2])
		s_split[array[1]] = ft_substr(s, array[2], array[0] - array[2]);
	return (s_split);
}*/
