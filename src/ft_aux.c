/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 11:37:02 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-21 11:37:02 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free2(char **str)
{
	if (str && *str)
		free(*str);
	if (str)
		*str = NULL;
}

void	ft_free_map(char ***map)
{
	int	i;

	if (!map || !*map)
		return ;
	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		(*map)[i] = NULL;
		i++;
	}
	free(*map);
	*map = NULL;
}

void	ft_init_map(t_map *map)
{
	map->dimensions.x = 0;
	map->dimensions.y = 0;
	map->pos.x = 0;
	map->pos.y = 0;
	map->map = NULL;
	map->exit = 0;
	map->collect = 0;
	map->moves = 0;
	map->players = 0;
	map->on_exit = 0;
}

void	ft_flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->dimensions.x || y >= map->dimensions.y
		|| map->map[y][x] == '1' || map->map[y][x] == 'F')
		return ;
	if (map->map[y][x] == 'C')
		map->collect--;
	if (map->map[y][x] == 'E')
		map->exit++;
	map->map[y][x] = 'F';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

void	ft_check_limits(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->dimensions.x)
	{
		if (map->map[0][i] != '1' || map->map[map->dimensions.y - 1][i] != '1')
		{
			ft_free_map(&map->map);
			perror("Error\nMap is not surrounded by walls");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i < map->dimensions.y)
	{
		if (map->map[i][0] != '1' || map->map[i][map->dimensions.x - 1] != '1')
		{
			ft_free_map(&map->map);
			perror("Error\nMap is not surrounded by walls");
			exit (1);
		}
		i++;
	}
}
