/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/17 09:45:56 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix_char(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

void	ft_print_matrix_char_2(char **matrix)
{
	int	i;

	i = 0;
	printf("-------------\n");
	while (matrix && matrix[i])
	{
		printf("+%s+\n", matrix[i]);
		i++;
	}
	printf("-------------\n");
}

//remove + +
/*void	ft_print_matrix_char_3(char **matrix)
{
	int	i;

	i = 0;
	printf("-------my matrix start-------\n");
	while (matrix && matrix[i])
	{
		printf("in position %i is +%s+\n", i, matrix[i]);
		i++;
	}
	printf("-------my matrix end-------\n");
}*/

int	ft_size_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

/* adds the second one to the first one */
/* frees the first one  */
/* returns the new one */
char	**ft_addmatrix(char **matrix_1, char **matrix_2)
{
	int		k;
	int		j;
	char	**new_matrix;

	new_matrix = malloc((ft_size_matrix(matrix_1)
				+ ft_size_matrix(matrix_2) + 1) * sizeof(char *));
	if (!new_matrix)
		return (NULL);
	k = 0;
	j = 0;
	while (matrix_1 && matrix_1[j])
	{
		new_matrix[j] = ft_strdup(matrix_1[j]);
		if (!new_matrix[j])
			return (ft_free_matrix(new_matrix));
		j++;
	}
	while (matrix_2 && matrix_2[k])
	{
		new_matrix[j + k] = ft_strdup(matrix_2[k]);
		if (!new_matrix[j + k])
			return (ft_free_matrix(new_matrix));
		k++;
	}
	return (new_matrix[j + k] = NULL, ft_free_matrix(matrix_1), new_matrix);
}

/* creates a deep copy (with memory, not just pointer to the same) */
/* of a matrix */
/* Doesn't free the first one */
char	**ft_matrixdup(char **matrix)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = 0;
	if (!matrix)
		return (NULL);
	while (matrix[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	while (j < i)
	{
		copy[j] = ft_strdup(matrix[j]);
		if (!copy[j])
		{
			ft_free_matrix(copy);
			return (NULL);
		}
		j++;
	}
	copy[i] = NULL;
	return (copy);
}

/* if the other one doesn t work */
/*char **ft_matrixdup(char **matrix)
{
    int i = 0;
    char **copy;

    if (!matrix)
        return NULL;
    while (matrix[i])
        i++;
    copy = malloc(sizeof(char *) * (i + 1));
    if (!copy)
        return (NULL);
    for (int j = 0; j < i; j++)
    {
        copy[j] = strdup(matrix[j]);
        if (!copy[j])
        {
            for (int k = 0; k < j; k++)
                free(copy[k]);
            free(copy);
            return NULL;
        }
    }
    copy[i] = NULL;
    return copy;
}*/

/*int main()
{
	char **matrix;
	char **a;
	char **b;
	
	a = ft_split("hola soy chris", ' ');
	if(!a)
		return (1);
	
	
	b = ft_split("adios no soy", ' ');
	if(!b)
	{
		ft_free_matrix(a);
		ft_free_matrix(b);
		return (1);
	}
	matrix = ft_addmatrix(a, b);
	if (!matrix)
		return (1);
	ft_print_matrix_char(matrix);
	ft_free_matrix(a);
	ft_free_matrix(b);
	
	ft_free_matrix(matrix);
}*/
