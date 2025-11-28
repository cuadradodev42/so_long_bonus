/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_images_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-25 14:40:04 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-25 14:40:04 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long_bonus.h"

void	ft_load_player_images(t_graphics *graphics)
{
	graphics->img_player = ft_calloc(4, sizeof(void *));
	if (!graphics->img_player)
	{
		perror("Error\nMemory allocation failed");
		exit (1);
	}
	ft_load_image(graphics, &graphics->img_player[0], "assets/player_up.xpm");
	ft_load_image(graphics, &graphics->img_player[1], "assets/player_down.xpm");
	ft_load_image(graphics, &graphics->img_player[2], "assets/player_left.xpm");
	ft_load_image(graphics, &graphics->img_player[3], "assets/player_right.xpm");
	if (!graphics->img_player[0] || !graphics->img_player[1]
		|| !graphics->img_player[2] || !graphics->img_player[3])
	{
		ft_destroy_player_images(graphics);
		perror("Error\nFailed to load player images\n");
		exit (1);
	}
}

void	ft_load_enemy_images(t_graphics *graphics)
{
	graphics->img_enemy = ft_calloc(4, sizeof(void *));
	if (!graphics->img_enemy)
	{
		perror("Error\nMemory allocation failed");
		exit (1);
	}
	ft_load_image(graphics, &graphics->img_enemy[0], "assets/enemy_up.xpm");
	ft_load_image(graphics, &graphics->img_enemy[1], "assets/enemy_down.xpm");
	ft_load_image(graphics, &graphics->img_enemy[2], "assets/enemy_left.xpm");
	ft_load_image(graphics, &graphics->img_enemy[3], "assets/enemy_right.xpm");
	if (!graphics->img_enemy[0] || !graphics->img_enemy[1]
		|| !graphics->img_enemy[2] || !graphics->img_enemy[3])
	{
		ft_destroy_enemy_images(graphics);
		perror("Error\nFailed to load enemy images\n");
		exit (1);
	}
}

void	ft_load_images(t_graphics *graphics)
{
	ft_load_image(graphics, &graphics->img_background,
		"assets/background.xpm");
	ft_load_image(graphics, &graphics->img_wall, "assets/wall.xpm");
	ft_load_image(graphics, &graphics->img_collect, "assets/collectible.xpm");
	ft_load_image(graphics, &graphics->img_exit, "assets/exit.xpm");
	ft_load_player_images(graphics);
	ft_load_enemy_images(graphics);
	if (!graphics->img_background || !graphics->img_wall
		|| !graphics->img_collect || !graphics->img_exit)
	{
		ft_destroy_images(graphics);
		perror("Error\nFailed to load images\n");
		exit (1);
	}
}

void	ft_put_image(t_graphics *graphics, void *img, int x, int y)
{
	mlx_put_image_to_window(graphics->mlx, graphics->win, img,
		x * graphics->img_size, y * graphics->img_size);
}

void	ft_put_players(t_graphics *graphics, t_map *map)
{
	ft_put_image(graphics, graphics->img_player[3], map->pos.x, map->pos.y);
	ft_put_image(graphics, graphics->img_player[2], map->player2_pos.x,
		map->player2_pos.y);
}
