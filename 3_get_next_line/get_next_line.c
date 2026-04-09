/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:35:12 by almaldon          #+#    #+#             */
/*   Updated: 2025/05/26 09:45:51 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*set_new_str(char	*str)
{
	char	*new_str;
	char	*tmp;
	int		len;

	tmp = ft_strchr(str, '\n');
	if (!tmp)
		return (ft_free(&str));
	len = (tmp - str) + 1;
	if (!str[len])
		return (ft_free(&str));
	new_str = ft_substr(str, len, ft_strlen(str) - len);
	ft_free(&str);
	if (!new_str)
		return (NULL);
	return (new_str);
}

static char	*extract_line(int fd, char *str)
{
	int		readbytes;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(&str));
	buff[0] = '\0';
	readbytes = 1;
	while (readbytes > 0 && !ft_strchr(buff, '\n'))
	{
		readbytes = read(fd, buff, BUFFER_SIZE);
		if (readbytes > 0)
		{
			buff[readbytes] = '\0';
			str = ft_strjoin(str, buff);
		}
	}
	free(buff);
	if (readbytes == -1)
		return (ft_free(&str));
	return (str);
}

static char	*fill_line(char *str)
{
	int		len;
	char	*line;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	len++;
	line = ft_substr(str, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((str && !ft_strchr(str, '\n')) || !str)
		str = extract_line(fd, str);
	if (!str)
		return (NULL);
	line = fill_line(str);
	if (!line)
		return (ft_free(&str));
	str = set_new_str(str);
	return (line);
}
