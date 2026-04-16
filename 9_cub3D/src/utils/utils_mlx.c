/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:20:29 by almaldon          #+#    #+#             */
/*   Updated: 2026/04/08 10:06:09 by almaldon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = game->mlx.addr + (y * game->mlx.line_len
			+ x * (game->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	destroy_textures(t_game *game)
{
	if (game->north.img)
		mlx_destroy_image(game->mlx.mlx, game->north.img);
	if (game->south.img)
		mlx_destroy_image(game->mlx.mlx, game->south.img);
	if (game->west.img)
		mlx_destroy_image(game->mlx.mlx, game->west.img);
	if (game->east.img)
		mlx_destroy_image(game->mlx.mlx, game->east.img);
}

int	close_game(t_game *game)
{
	destroy_textures(game);
	if (game->mlx.img)
		mlx_destroy_image(game->mlx.mlx, game->mlx.img);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->mlx.mlx)
	{
		mlx_destroy_display(game->mlx.mlx);
		free(game->mlx.mlx);
	}
	free_game(game);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}

int	get_line_len(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}
