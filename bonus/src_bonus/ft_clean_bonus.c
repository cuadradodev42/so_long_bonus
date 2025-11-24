/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-23 17:21:03 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-23 17:21:03 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_clear_old_pos_player(t_graphics *graphics, t_map *map)
{
	if (map->map[map->pos.y][map->pos.x] == EXIT)
		ft_put_image(graphics, graphics->img_exit, map->pos.x, map->pos.y);
	else
		ft_put_image(graphics, graphics->img_background,
			map->pos.x, map->pos.y);
}

void	ft_clear_old_pos_player2(t_graphics *graphics, t_map *map)
{
	if (map->map[map->player2_pos.y][map->player2_pos.x] == EXIT)
		ft_put_image(graphics, graphics->img_exit,
			map->player2_pos.x, map->player2_pos.y);
	else
		ft_put_image(graphics, graphics->img_background,
			map->player2_pos.x, map->player2_pos.y);
}

void	ft_free_all(t_map *map)
{
	if (!map)
		return ;
	ft_free_enemies(map->enemies);
	map->enemies = NULL;
	ft_free_map(&map->map);
}
