/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/08/10 14:28:55 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_stuff(char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == 'm')
			ft_free_matrix(va_arg(args, char **));
		else if (str[i] == 'a')
			free(va_arg(args, int *));
		else if (str[i] == 's')
			free(va_arg(args, char *));
		else if (str[i] == '3')
			ft_free_3pters(va_arg(args, char ***));
		i++;
	}
	va_end(args);
	return (NULL);
}

/* no se si funciona */
/*void	*ft_free_string(char *str)
{
	if(!str)
		return (NULL);
	free(str);
	return (NULL);
}*/

void	*ft_free_matrix(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (NULL);
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (NULL);
}

char	***ft_free_3pters(char ***triple)
{
	int	i;

	i = 0;
	while (triple && triple[i])
	{
		ft_free_stuff("m", triple[i]);
		i++;
	}
	free(triple);
	return (NULL);
}

/*void	*ft_free_node(t_node *n_node)
{
	t_node	*start;
	t_node	*n_temp;

	if (!n_node)
		return (NULL);
	start = n_node;
	while (1)
	{
		n_temp = n_node->next;
		free(n_node);
		n_node = n_temp;
		if (!n_node || n_node == start)
			break ;
	}
	return (NULL);
}*/
