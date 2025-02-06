/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:29:34 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/16 00:31:31 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_images(t_game *game)
{
	int	width;
	int	height;

	game->textures->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&width, &height);
	game->textures->balls = mlx_xpm_file_to_image(game->mlx,
			"textures/balls.xpm", &width, &height);
	game->textures->balls_2 = mlx_xpm_file_to_image(game->mlx,
			"textures/balls_2.xpm", &width, &height);
}

void	render_map(t_game *game, char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (y < 20)
	{
		x = 0;
		while (x < 40)
		{
			if (grid[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->floor, x * 64, y * 64);
			else if (grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->balls, x * 64, y * 64);
			else if (grid[y][x] == '2')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->balls_2, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
