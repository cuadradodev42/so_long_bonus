/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-22 12:05:00 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-22 12:05:00 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_map(t_map *map)
{
	map->dimensions.x = 0;
	map->dimensions.y = 0;
	map->pos.x = 0;
	map->pos.y = 0;
	map->player2_pos.x = 0;
	map->player2_pos.y = 0;
	map->map = NULL;
	map->exit = 0;
	map->collect = 0;
	map->moves = 0;
	map->players = 0;
	map->on_exit = 0;
	map->p1_collect = 0;
	map->p2_collect = 0;
	map->p2_moves = 0;
	map->enemies = NULL;
}

void	ft_create_map(int fd, t_map *map)
{
	int		i;
	char	*line;

	map->map = malloc((map->dimensions.y + 1) * sizeof(char *));
	if (!map->map)
	{
		perror("Error\nMemory allocation failed");
		exit (1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	ft_free2(&line);
	map->map[i] = NULL;
}

void	ft_duplicate_var_map(t_map *map, t_map *new_map)
{
	new_map->dimensions = map->dimensions;
	new_map->pos = map->pos;
	new_map->player2_pos = map->player2_pos;
	new_map->exit = map->exit;
	new_map->collect = map->collect;
	new_map->moves = map->moves;
	new_map->players = map->players;
	new_map->on_exit = map->on_exit;
	new_map->p1_collect = map->p1_collect;
	new_map->p2_collect = map->p2_collect;
	new_map->p2_moves = map->p2_moves;
	new_map->enemies = NULL;
}

t_map	ft_duplicate_map(t_map *map)
{
	t_map	new_map;
	int		i;

	ft_duplicate_var_map(map, &new_map);
	new_map.map = malloc((map->dimensions.y + 1) * sizeof(char *));
	if (!new_map.map)
	{
		perror("Error\nMemory allocation failed");
		exit (1);
	}
	i = 0;
	while (i < map->dimensions.y)
	{
		new_map.map[i] = ft_strdup(map->map[i]);
		if (!new_map.map[i])
		{
			ft_free_all(&new_map);
			perror("Error\nMemory allocation failed");
			exit (1);
		}
		i++;
	}
	new_map.map[i] = NULL;
	return (new_map);
}
