/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-25 14:39:13 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-25 14:39:13 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_images(t_graphics *graphics)
{
	if (graphics->img_background)
		mlx_destroy_image(graphics->mlx, graphics->img_background);
	if (graphics->img_wall)
		mlx_destroy_image(graphics->mlx, graphics->img_wall);
	if (graphics->img_collect)
		mlx_destroy_image(graphics->mlx, graphics->img_collect);
	if (graphics->img_exit)
		mlx_destroy_image(graphics->mlx, graphics->img_exit);
}

void	ft_destroy_player_images(t_graphics *graphics)
{
	if (graphics->img_player)
	{
		if (graphics->img_player[0])
			mlx_destroy_image(graphics->mlx, graphics->img_player[0]);
		if (graphics->img_player[1])
			mlx_destroy_image(graphics->mlx, graphics->img_player[1]);
		if (graphics->img_player[2])
			mlx_destroy_image(graphics->mlx, graphics->img_player[2]);
		if (graphics->img_player[3])
			mlx_destroy_image(graphics->mlx, graphics->img_player[3]);
		free(graphics->img_player);
	}
}

void	ft_destroy_enemy_images(t_graphics *graphics)
{
	if (graphics->img_enemy)
	{
		if (graphics->img_enemy[0])
			mlx_destroy_image(graphics->mlx, graphics->img_enemy[0]);
		if (graphics->img_enemy[1])
			mlx_destroy_image(graphics->mlx, graphics->img_enemy[1]);
		if (graphics->img_enemy[2])
			mlx_destroy_image(graphics->mlx, graphics->img_enemy[2]);
		if (graphics->img_enemy[3])
			mlx_destroy_image(graphics->mlx, graphics->img_enemy[3]);
		free(graphics->img_enemy);
	}
}

void	ft_close(t_graphics *graphics, char *message)
{
	if (message)
		perror(message);
	ft_close_window(graphics);
	exit (1);
}
