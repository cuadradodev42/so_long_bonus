/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-25 14:39:56 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-25 14:39:56 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_window_size(t_graphics *graphics, t_map *map)
{
	int	window_size_x;
	int	window_size_y;
	int	screen_size_x;
	int	screen_size_y;

	mlx_get_screen_size(graphics->mlx, &screen_size_x, &screen_size_y);
	window_size_x = map->dimensions.x * graphics->img_size;
	window_size_y = map->dimensions.y * graphics->img_size;
	if (window_size_x > screen_size_x)
		ft_close(graphics, "Error\nWindow width exceeds screen size\n");
	if (window_size_y > screen_size_y)
		ft_close(graphics, "Error\nWindow height exceeds screen size\n");
	graphics->win = mlx_new_window(graphics->mlx,
			window_size_x, window_size_y, "So Long");
	if (!graphics->win)
		ft_close(graphics, "Error\nFailed to create window\n");
}

void	ft_put_enemys(t_graphics *graphics, t_map *map)
{
	t_enemy	*current;

	current = map->enemies;
	while (current)
	{
		ft_put_enemy_rotating(graphics, current->x, current->y);
		current = current->next;
	}
}

void	ft_render_map(t_graphics *graphics, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->dimensions.y)
	{
		x = 0;
		while (x < map->dimensions.x)
		{
			if (map->map[y][x] == BACKGROUND || map->map[y][x] == PLAYER_START)
				ft_put_image(graphics, graphics->img_background, x, y);
			else if (map->map[y][x] == WALL)
				ft_put_image(graphics, graphics->img_wall, x, y);
			else if (map->map[y][x] == COLLECT)
				ft_put_image(graphics, graphics->img_collect, x, y);
			else if (map->map[y][x] == EXIT)
				ft_put_image(graphics, graphics->img_exit, x, y);
			x++;
		}
		y++;
	}
	ft_put_players(graphics, map);
	ft_put_enemys(graphics, map);
}
