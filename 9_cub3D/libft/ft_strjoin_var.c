/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:39:44 by chanin            #+#    #+#             */
/*   Updated: 2025/08/13 19:56:28 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates a new string */
/* Doesn't free anything */
void	*ft_strjoin_var(int count, ...)
{
	va_list	args;
	char	*str;
	char	*temp;
	int		i;

	str = ft_strdup("");
	if (!str)
		return (NULL);
	va_start(args, count);
	i = 0;
	while (i < count)
	{
		temp = ft_strjoin(str, va_arg(args, char *));
		free(str);
		if (!temp)
		{
			va_end(args);
			return (NULL);
		}
		str = temp;
		i++;
	}
	va_end(args);
	return (str);
}

void	*ft_unsplit(char **matrix)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (matrix && matrix[i])
	{
		tmp = ft_strjoin(str, matrix[i]);
		free(str);
		if (!tmp)
			return (NULL);
		str = tmp;
		i++;
	}
	return (str);
}

void	*ft_unsplit_spaced(char **matrix)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (matrix && matrix[i])
	{
		if (i == 0)
			tmp = ft_strjoin_var(2, str, matrix[i]);
		else
			tmp = ft_strjoin_var(3, str, " ", matrix[i]);
		free(str);
		if (!tmp)
			return (NULL);
		str = tmp;
		i++;
	}
	return (str);
}

/*int main()
{
    char *s1 = "a bb ccc dddd eeeee";
	char **matrix = ft_split(s1, ' ');
	if(!matrix)
		return (0);
    char *final = ft_unsplit_spaced(matrix);
	if (!final)
		return (ft_free_stuff("m", matrix), 0);
    printf("%s\n", final);
	ft_free_stuff("m", matrix);
	free(final);
    return (0);
}*/

/*int main()
{
    char *s1 = "a";
    char *s2 = "bb";
    char *s3 = "ccc";
    char *s4 = "dddd";
    char *s5 = "eeeee";
    char *final;

    final = ft_strjoin_var(5, s1, s2, s3, s4, s5);
	if (!final)
		return (0);
    printf("%s\n", final);
	free(final);
    return (0);
}*/
