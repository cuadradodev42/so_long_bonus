/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 16:31:52 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-21 16:31:52 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_process_element(t_map *map, int i, int j)
{
	if (map->map[i][j] != BACKGROUND && map->map[i][j] != WALL)
	{
		ft_free_map(&map->map);
		perror("Error\nInvalid character in map");
		exit (1);
	}
}

void	ft_count_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->dimensions.y)
	{
		j = 0;
		while (j < map->dimensions.x)
		{
			if (map->map[i][j] == COLLECT)
				map->collect++;
			else if (map->map[i][j] == EXIT)
				map->exit++;
			else if (map->map[i][j] == PLAYER_START)
			{
				map->players++;
				map->pos.x = j;
				map->pos.y = i;
			}
			else
				ft_process_element(map, i, j);
			j++;
		}
		i++;
	}
}

void	map_transitable_error(t_map *map, t_map *map_copy)
{
	ft_free_map(&map_copy->map);
	ft_free_map(&map->map);
	perror("Error\nMap is not transitable");
	exit (1);
}

void	ft_check_transitable_map(t_map *map)
{
	t_position	pos;
	t_map		map_copy;
	int			collect_num;

	collect_num = map->collect;
	pos.x = map->pos.x;
	pos.y = map->pos.y;
	map_copy = ft_duplicate_map(map);
	map_copy.exit = 0;
	ft_flood_fill(&map_copy, pos.x, pos.y);
	if (map_copy.collect > 0 || map_copy.exit == 0)
		map_transitable_error(map, &map_copy);
	ft_free_map(&map_copy.map);
}

t_map	ft_duplicate_map(t_map *map)
{
	t_map	new_map;
	int		i;

	ft_init_map(&new_map);
	new_map.dimensions.x = map->dimensions.x;
	new_map.dimensions.y = map->dimensions.y;
	new_map.pos.x = map->pos.x;
	new_map.pos.y = map->pos.y;
	new_map.exit = map->exit;
	new_map.collect = map->collect;
	new_map.players = map->players;
	new_map.map = malloc((new_map.dimensions.y + 1) * sizeof(char *));
	if (!new_map.map)
	{
		perror("Error\nMemory allocation failed");
		exit (1);
	}
	i = 0;
	while (i < new_map.dimensions.y)
	{
		new_map.map[i] = ft_strdup(map->map[i]);
		i++;
	}
	new_map.map[i] = NULL;
	return (new_map);
}
