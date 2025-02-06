/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 03:53:07 by apiscopo          #+#    #+#             */
/*   Updated: 2024/12/16 01:55:34 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_grid(char **grid)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

void	free_resources(t_game *game)
{
	if (game->textures->floor)
		mlx_destroy_image(game->mlx, game->textures->floor);
	if (game->textures->balls)
		mlx_destroy_image(game->mlx, game->textures->balls);
	if (game->textures->balls_2)
		mlx_destroy_image(game->mlx, game->textures->balls_2);
	free_ressources_grid(game);
}

void	free_ressources_grid(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->win)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game->textures)
		free(game->textures);
	free_grid(game->grid);
	free_grid(game->grid_bis);
	exit(0);
}
