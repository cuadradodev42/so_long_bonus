/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 18:33:08 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-24 18:33:08 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (graphics->img_player)
		mlx_destroy_image(graphics->mlx, graphics->img_player);
}

void	ft_close(t_graphics *graphics, char *message)
{
	if (message)
		perror(message);
	ft_close_window(graphics);
	exit (1);
}
