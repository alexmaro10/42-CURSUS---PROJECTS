/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:44:29 by almaldon          #+#    #+#             */
/*   Updated: 2025/06/27 09:01:02 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inlcudes/so_long.h"

void	n_collect(char **map, int *collect)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				count++;
		}
	}
	*collect = count;
}

char	*space_draft(const char *input)
{
	int		i;
	int		j;
	int		length;
	char	*resultado;

	i = -1;
	j = 0;
	length = 0;
	while (input[length] != '\0')
		length++;
	resultado = malloc(length + 1);
	if (!resultado)
		return (NULL);
	while (++i < length)
	{
		if (input[i] != ' ')
			resultado[j++] = input[i];
	}
	resultado[j] = '\0';
	return (resultado);
}

static char	*ft_strjoin_temp(char *s1, const char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	if (s1)
		ft_memcpy(res, s1, len1);
	if (s2)
		ft_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	free(s1);
	return (res);
}

static void	initialize_var(int *fd, char *file, char **line, char **joined)
{
	*joined = NULL;
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		ft_error("Could not open the map");
	*line = get_next_line(*fd);
	if (!*line)
		ft_error("Empty map");
}

char	**read_map(char *file)
{
	int		fd;
	char	*line;
	char	*joined;
	char	**map;
	int		i;

	i = -1;
	initialize_var(&fd, file, &line, &joined);
	while (line)
	{
		joined = ft_strjoin_temp(joined, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(joined, '\n');
	while (map[++i])
	{
		line = map[i];
		map[i] = space_draft(map[i]);
		free(line);
	}
	free(joined);
	return (map);
}
