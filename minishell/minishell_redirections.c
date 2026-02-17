/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:02:36 by almaldon          #+#    #+#             */
/*   Updated: 2025/09/11 09:00:22 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_input(t_redirect *r)
{
	int	fd;

	fd = open(r->file, O_RDONLY);
	if (fd < 0)
	{
		perror(r->file);
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("dup2 input");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

static int	handle_output(t_redirect *r)
{
	int	fd;

	if (r->type == REDIR_APP)
		fd = open(r->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(r->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(r->file);
		return (-1);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2 output");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

static int	handle_heredoc(t_redirect *r)
{
	int		pipefd[2];
	char	*line;

	if (pipe(pipefd) < 0)
		return (perror("pipe"), -1);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, r->file) == 0)
			break ;
		write(pipefd[1], line, ft_strlen(line));
		write(pipefd[1], "\n", 1);
		free(line);
	}
	free(line);
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
	{
		perror("dup2 heredoc");
		close(pipefd[0]);
		return (-1);
	}
	close(pipefd[0]);
	return (0);
}

int	apply_redirections(t_command *cmd)
{
	int			i;
	t_redirect	*r;

	i = 0;
	while (i < cmd->redirect_count)
	{
		r = &cmd->redirects[i];
		if (r->type == REDIR_IN && handle_input(r) < 0)
			return (-1);
		else if ((r->type == REDIR_OUT || r->type == REDIR_APP)
			&& handle_output(r) < 0)
			return (-1);
		else if (r->type == REDIR_HEREDOC && handle_heredoc(r) < 0)
			return (-1);
		i++;
	}
	return (0);
}
