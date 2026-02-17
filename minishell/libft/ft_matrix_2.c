/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/14 11:01:06 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	**ft_addstring_free(char **matrix_1, char **matrix_2, char *string)
{
	if (matrix_1)
		ft_free_matrix(matrix_1);
	if (matrix_2)
		ft_free_matrix(matrix_2);
	if (string)
		free(string);
	return (NULL);
}*/

//return (ft_addstring_free(matrix, new_matrix, string)); ?
//change the name with matrix ?
/* Adds a string at the end of a matrix and creates a new matrix with memory */
/* Frees only the first matrix */
/* Returns the new matrix */
char	**ft_addstring(char **matrix, char *string)
{
	int		i;
	char	**new_matrix;

	i = 0;
	while (matrix && matrix[i])
		i++;
	new_matrix = malloc ((i + 2) * sizeof(char *));
	if (!new_matrix)
		return (ft_free_matrix(new_matrix));
	i = 0;
	while (matrix && matrix[i])
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		if (!new_matrix[i])
			return (ft_free_matrix(new_matrix));
		i++;
	}
	new_matrix[i] = ft_strdup(string);
	if (!new_matrix[i])
		return (ft_free_stuff("mms", matrix, new_matrix, string));
	new_matrix[i + 1] = NULL;
	ft_free_matrix(matrix);
	return (new_matrix);
}

static int	ft_clean_matrix_aux(char **matrix, char *dirt)
{
	int		i;
	int		k;
	int		len_dirt;

	if (!matrix)
		return (-1);
	if (!dirt)
		return (ft_size_matrix(matrix));
	i = 0;
	k = 0;
	len_dirt = ft_strlen(dirt);
	while (matrix[k])
	{
		if (ft_strncmp(matrix[k], dirt, len_dirt + 1) != 0)
			i++;
		k++;
	}
	return (i);
}

static int	ft_clean_utils(int *len_clean, int *j, char **matrix, char *dirt)
{
	*j = 0;
	*len_clean = ft_clean_matrix_aux(matrix, dirt);
	return (0);
}

/* Creates a new matrix removing an array of the old matrix  */
/* Frees the old matrix */
char	**ft_clean_matrix(char **matrix, char *dirt)
{
	int		len_clean;
	int		j;
	int		k;
	char	**clean;

	k = ft_clean_utils(&len_clean, &j, matrix, dirt);
	if (len_clean == -1)
		return (NULL);
	clean = malloc(sizeof(char *) * (len_clean + 1));
	if (!clean)
		return (ft_free_matrix(matrix));
	while (j < len_clean)
	{
		while (matrix[j + k]
			&& ft_strncmp(matrix[j + k], dirt, ft_strlen(dirt) + 1) == 0)
			k++;
		if (!matrix[j + k])
			break ;
		clean[j] = ft_strdup(matrix[j + k]);
		if (!clean[j])
			return (ft_free_stuff("mm", matrix, clean));
		j++;
	}
	clean[len_clean] = NULL;
	return (ft_free_matrix(matrix), clean);
}

/*char	**ft_clean_matrix(char **matrix, char *dirt)
{
	int		len_clean;
	int		j;
	int		k;
	int		len_dirt;
	char	**cleaned;

	len_dirt = ft_strlen(dirt);
	len_clean = ft_clean_matrix_aux(matrix, dirt);
	if (len_clean == -1)
		return (NULL);
	cleaned = malloc(sizeof(char *) * (len_clean + 1));
	if (!cleaned)
		return (ft_free_matrix(matrix));
	k = 0;
	j = 0;
	while (j < len_clean)
	{
		while (matrix[j + k]
			&& ft_strncmp(matrix[j + k], dirt, len_dirt + 1) == 0)
			k++;
		if (!matrix[j + k])
			break ;
		cleaned[j] = ft_strdup(matrix[j + k]);
		if (!cleaned[j])
			return (ft_free_stuff("mm", matrix, cleaned));
		j++;
	}
	cleaned[len_clean] = NULL;
	return (ft_free_matrix(matrix), cleaned);
}*/

/*int main()
{
    char *s1 = "a bb bbccc bb dddd  bb bb eeeeebb bb";
	char **matrix = ft_split(s1, ' ');
	if(!matrix)
		return (0);
	matrix = ft_clean_matrix(matrix, "bb");
	if(!matrix)
		return (0);
	ft_print_matrix_char(matrix);
	ft_free_matrix(matrix);
	return (0);
}*/