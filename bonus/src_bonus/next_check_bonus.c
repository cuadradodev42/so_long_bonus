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

#include "so_long_bonus.h"

void	ft_error_msg(char *msg, t_map *map)
{
	ft_free_all(map);
	perror(msg);
	exit (1);
}

void	ft_process_player_start(t_map *map, int i, int j)
{
	map->players++;
	if (map->players == 1)
	{
		map->pos.x = j;
		map->pos.y = i;
	}
	else if (map->players == 2)
	{
		map->player2_pos.x = j;
		map->player2_pos.y = i;
		map->map[i][j] = BACKGROUND;
	}
}

void	ft_process_element(t_map *map, int i, int j)
{
	char	cell;

	cell = map->map[i][j];
	if (cell == COLLECT)
		map->collect++;
	else if (cell == EXIT)
		map->exit++;
	else if (cell == PLAYER_START)
		ft_process_player_start(map, i, j);
	else if (cell != WALL && cell != BACKGROUND && cell != ENEMY)
		ft_error_msg("Error\nInvalid character in map", map);
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
			ft_process_element(map, i, j);
			j++;
		}
		i++;
	}
}
