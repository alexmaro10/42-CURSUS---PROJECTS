/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:51:59 by almaldon          #+#    #+#             */
/*   Updated: 2025/09/15 13:44:13 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <string.h>
#include <stdlib.h>

static int	handle_redirect(t_command *cmd, char **tokens, int *i, int type)
{
	if (!tokens[*i] || cmd->redirect_count >= MAX_REDIRS)
		return (-1);
	cmd->redirects[cmd->redirect_count].type = type;
	cmd->redirects[cmd->redirect_count].file = ft_strdup(tokens[*i]);
	cmd->redirect_count++;
	return (0);
}

static int	process_token(t_command *cmd, char **tokens, int *i, int *argc)
{
	if (!ft_strcmp(tokens[*i], "<"))
	{
		(*i)++;
		return (handle_redirect(cmd, tokens, i, REDIR_IN));
	}
	else if (!ft_strcmp(tokens[*i], ">"))
	{
		(*i)++;
		return (handle_redirect(cmd, tokens, i, REDIR_OUT));
	}
	else if (!ft_strcmp(tokens[*i], ">>"))
	{
		(*i)++;
		return (handle_redirect(cmd, tokens, i, REDIR_APP));
	}
	else if (!ft_strcmp(tokens[*i], "<<"))
	{
		(*i)++;
		return (handle_redirect(cmd, tokens, i, REDIR_HEREDOC));
	}
	else
	{
		cmd->argv[(*argc)++] = ft_strdup(tokens[*i]);
	}
	return (0);
}

//quitar el 2do return -1 ?
int	parse_command(char **tokens, t_command *cmd)
{
	int	argc;
	int	i;

	if (!tokens)
		return (-1);
	cmd->redirect_count = 0;
	argc = 0;
	i = 0;
	while (tokens[i] && argc < MAX_ARGS - 1)
	{
		if (process_token(cmd, tokens, &i, &argc) == -1)
			return (ft_free_stuff("m", tokens), -1);
		i++;
	}
	cmd->argv[argc] = NULL;
	if (argc == 0)
		return (ft_free_stuff("m", tokens), -1);
	return (ft_free_stuff("m", tokens), 0);
}
