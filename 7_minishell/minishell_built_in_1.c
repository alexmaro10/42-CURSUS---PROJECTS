/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_built_in_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/09/17 10:03:25 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	**ft_matrix_alpha(char **matrix)
{
	int	i;
	int	j;
	int	size;

	if (!matrix)
		return (NULL);
	size = ft_size_matrix(matrix);
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(matrix[j], matrix[j + 1]) > 0)
				ft_swap_str(&matrix[j], &matrix[j + 1]);
			j++;
		}
		i++;
	}
	return (matrix);
}

void	ft_export_0(char **env)
{
	char	***env_3;
	char	**copy_env;
	int		i;

	i = 0;
	copy_env = ft_matrixdup(env);
	if (!copy_env)
		return ;
	copy_env = ft_matrix_alpha(copy_env);
	env_3 = ft_env_3(copy_env);
	if (!env_3)
		ft_free_stuff("m", copy_env);
	while (env_3[i])
	{
		printf("declare -x ");
		printf("%s", env_3[i][0]);
		if (env_3[i][1])
			printf("=\"%s\"", env_3[i][1]);
		printf("\n");
		i++;
	}
	ft_free_stuff("m3", copy_env, env_3);
}

int	ft_export_1_aux(char ***matrix, char *str)
{
	int		i;
	char	*clean;

	i = 0;
	clean = ft_substr(str, 0, ft_strchr_4(str, '='));
	if (!clean)
		return (-2);
	while (matrix && matrix[i])
	{
		if (ft_strcmp(matrix[i][0], clean) == 0)
			return (free(clean), i);
		i++;
	}
	free(clean);
	return (-1);
}

char	**ft_export_1(char **env, char *var, char ***env_3)
{
	int		pos;
	char	*tmp;

	tmp = NULL;
	if (ft_isalpha(var[0]) == 0 && var[0] != '_')
	{
		printf("export: `%s': not a valid identifier\n", var);
		return (env);
	}
	pos = ft_export_1_aux(env_3, var);
	if (pos == -2)
		return (printf("ft_substr error\n"), NULL);
	else if (pos == -1)
		env = ft_addstring(env, var);
	else if (pos >= 0 && ft_strchr(var, '='))
	{
		tmp = ft_strdup(var);
		if (!tmp)
			return (env);
		free(env[pos]);
		env[pos] = tmp;
		return (env);
	}
	return (env);
}
