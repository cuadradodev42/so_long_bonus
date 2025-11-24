/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 21:13:39 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-24 21:13:39 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_image(t_graphics *graphics, void **img, char *path)
{
	*img = mlx_xpm_file_to_image(graphics->mlx,
			path, &graphics->img_size, &graphics->img_size);
	if (!*img)
	{
		ft_destroy_images(graphics);
		ft_close(graphics, "Error\nFailed to load images\n");
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
	ft_load_image(graphics, &graphics->img_player, "assets/player.xpm");
	if (!graphics->img_background || !graphics->img_wall
		|| !graphics->img_collect || !graphics->img_exit
		|| !graphics->img_player)
	{
		ft_destroy_images(graphics);
		ft_close(graphics, "Error\nFailed to load images\n");
		exit (1);
	}
}

void	ft_put_image(t_graphics *graphics, void *img, int x, int y)
{
	mlx_put_image_to_window(graphics->mlx, graphics->win, img,
		x * graphics->img_size, y * graphics->img_size);
}
