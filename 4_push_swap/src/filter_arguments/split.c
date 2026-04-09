/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:59:47 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/20 14:08:50 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	long	n1;
	long	n2;

	n1 = ft_atoi(str1);
	n2 = ft_atoi(str2);
	if (n1 > n2)
		return (1);
	else if (n2 > n1)
		return (-1);
	return (0);
}

int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
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

int	len_word(char const *s, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

int	fill_word(char *word, char const *s, char c)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
		word[j++] = s[i++];
	word[j] = '\0';
	while (s[i] && s[i] == c)
		i++;
	return (i);
}
