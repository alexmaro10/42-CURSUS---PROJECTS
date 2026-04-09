/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:56:46 by almaldon          #+#    #+#             */
/*   Updated: 2025/09/15 14:17:29 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	proc_subcommand(char **tokens, int start, int end, t_command *cmd)
{
	int		len;
	char	**subtokens;
	int		j;

	len = end - start;
	subtokens = ft_calloc(len + 1, sizeof(char *));
	if (!subtokens)
		return (-1);
	j = -1;
	while (++j < len)
		subtokens[j] = ft_strdup(tokens[start + j]);
	subtokens[len] = NULL;
	if (parse_command(subtokens, cmd) != 0)
		return (-1);
	return (0);
}

static int	get_end(char **tokens, int i)
{
	int	end;

	if (ft_strcmp(tokens[i], "|") == 0)
		end = i;
	else
		end = i + 1;
	return (end);
}

static bool	parse_aux(char **tokens)
{
	if (ft_strcmp(tokens[0], "|") == 0
		|| ft_strcmp(tokens[ft_size_matrix(tokens) - 1], "|") == 0)
		return (0);
	return (1);
}

int	parse_pipeline(char **tokens, t_pipeline *pl)
{
	int	start;
	int	i;
	int	end;

	start = 0;
	pl->count = 0;
	i = -1;
	pl->cmds = ft_calloc(MAX_ARGS, sizeof(t_command));
	if (!pl->cmds)
		return (-1);
	while (tokens[++i])
	{
		if (!parse_aux(tokens))
			return (-1);
		if (ft_strcmp(tokens[i], "|") == 0 || tokens[i + 1] == NULL)
		{
			end = get_end(tokens, i);
			if (proc_subcommand(tokens, start, end, &pl->cmds[pl->count]) != 0)
				return (-1);
			pl->count++;
			if (ft_strcmp(tokens[i], "|") == 0)
				start = i + 1;
		}
	}
	return (0);
}
