/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 17:05:12 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-24 17:05:12 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_transitable_error(t_map *map, t_map *map_copy)
{
	ft_free_all(map_copy);
	ft_error_msg("Error\nMap is not transitable", map);
}

void	ft_check_transitable_map(t_map *map)
{
	t_position	pos;
	t_position	pos2;
	t_map		map_copy;	
	int			collect_num;

	collect_num = map->collect;
	pos.x = map->pos.x;
	pos.y = map->pos.y;
	pos2.x = map->player2_pos.x;
	pos2.y = map->player2_pos.y;
	map_copy = ft_duplicate_map(map);
	map_copy.exit = 0;
	ft_flood_fill(&map_copy, pos.x, pos.y);
	if (map_copy.collect > 0 || map_copy.exit == 0)
		map_transitable_error(map, &map_copy);
	map_copy.collect = collect_num;
	map_copy.exit = 0;
	ft_flood_fill(&map_copy, pos2.x, pos2.y);
	if (map_copy.collect > 0 || map_copy.exit == 0)
		map_transitable_error(map, &map_copy);
	ft_free_all(&map_copy);
}
