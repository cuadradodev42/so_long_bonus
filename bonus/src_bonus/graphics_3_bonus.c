/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 11:52:25 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-21 11:52:25 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_window(t_graphics *graphics)
{
	if (graphics->img_background)
		mlx_destroy_image(graphics->mlx, graphics->img_background);
	if (graphics->img_wall)
		mlx_destroy_image(graphics->mlx, graphics->img_wall);
	if (graphics->img_collect)
		mlx_destroy_image(graphics->mlx, graphics->img_collect);
	if (graphics->img_exit)
		mlx_destroy_image(graphics->mlx, graphics->img_exit);
	ft_destroy_player_images(graphics);
	ft_destroy_enemy_images(graphics);
	if (graphics->win)
		mlx_destroy_window(graphics->mlx, graphics->win);
	if (graphics->mlx)
	{
		mlx_destroy_display(graphics->mlx);
		free(graphics->mlx);
	}
	if (graphics->map)
		ft_free_all(graphics->map);
	exit (0);
	return (0);
}

void	ft_clear_old_pos(t_graphics *graphics)
{
	t_map	*map;

	map = graphics->map;
	if (map->on_exit)
	{
		map->map[map->pos.y][map->pos.x] = EXIT;
		ft_put_image(graphics, graphics->img_exit, map->pos.x, map->pos.y);
		map->on_exit = 0;
	}
	else
	{
		map->map[map->pos.y][map->pos.x] = BACKGROUND;
		ft_put_image(graphics, graphics->img_background,
			map->pos.x, map->pos.y);
	}
}

void	ft_player_on_exit(t_graphics *graphics, int new_x, int new_y)
{
	t_map	*map;
	double	p1_ratio;
	double	p2_ratio;

	map = graphics->map;
	if (map->map[new_y][new_x] == EXIT)
	{
		if (map->collect == 0)
		{
			p1_ratio = (double)(map->moves + 1) / (map->p1_collect + 1);
			p2_ratio = (double)(map->p2_moves + 1) / (map->p2_collect + 1);
			if (p1_ratio > p2_ratio)
				ft_printf("Player 2 Wins! why? Is a Mystery...\n");
			else if (p2_ratio > p1_ratio)
				ft_printf("Player 1 Wins! why? Is a Mystery...\n");
			else
				ft_printf("It's a draw! why? Is a Mystery...\n");
			ft_close_window(graphics);
		}
		else
			map->on_exit = 1;
	}
}
