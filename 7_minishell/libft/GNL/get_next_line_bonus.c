/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:05:45 by chanin            #+#    #+#             */
/*   Updated: 2025/06/14 12:45:47 by chanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_free_gnl(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free_gnl(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free_gnl(&storage));
	new_storage = ft_substr_gnl(storage, len, ft_strlen_gnl(storage) - len);
	ft_free_gnl(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr_gnl(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*readbuf(int fd, char *storage)
{
	int		rid;
	char	*buffer;

	rid = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_gnl(&storage));
	buffer[0] = '\0';
	while (rid > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		rid = read(fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			storage = ft_strjoin_gnl(storage, buffer);
		}
	}
	free(buffer);
	if (rid == -1)
		return (ft_free_gnl(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage[fd] && !ft_strchr_gnl(storage[fd], '\n')) || !storage[fd])
		storage[fd] = readbuf(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = new_line(storage[fd]);
	if (!line)
		return (ft_free_gnl(&storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}

/*int	main(int argc, char **argv)
{
	int	*fd;
	char **lines;
	int	i;
	int	files_done;
	int	total_files;

	if (argc < 2)
	{
		write(2, "file?\n", 6);
		return (1);
	}
	total_files = argc - 1;
	fd = malloc(sizeof(int) * total_files);
	lines = malloc(sizeof(char *) * total_files);
	if (!fd || !lines)
	{
		perror("malloc");
		return (1);
	}
	i = 0;
	while (i < total_files)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		if (fd[i] == -1)
		{
			perror("open");
			while (--i >= 0)
				close(fd[i]);
			free(fd);
			free(lines);
			return (1);
		}
		lines[i] = NULL;
		i++;
	}
	files_done = 0;
	while (files_done < total_files)
	{
		files_done = 0;
		i = 0;
		while (i < total_files)
		{
			if (fd[i] == -1)
			{
				files_done++;
			}
			else
			{
				lines[i] = get_next_line(fd[i]);
				if (lines[i])
				{
					printf("%s", lines[i]);
					free(lines[i]);
				}
				else
				{
					close(fd[i]);
					fd[i] = -1;
					files_done++;
				}
			}
			i++;
		}
	}
	free(fd);
	free(lines);
	return (0);
}*/
