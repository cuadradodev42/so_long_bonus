/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-23 15:08:01 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-23 15:08:01 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_flood_fill(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->dimensions.x || y >= map->dimensions.y
		|| map->map[y][x] == '1' || map->map[y][x] == 'F'
		|| map->map[y][x] == ENEMY)
		return ;
	if (map->map[y][x] == 'C')
		map->collect--;
	if (map->map[y][x] == 'E')
		map->exit = 1;
	map->map[y][x] = 'F';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

void	ft_print_moves_p1(t_graphics *graphics, t_map *map)
{
	char	*moves_str;
	char	*moves;

	moves_str = ft_itoa(map->moves);
	if (moves_str)
	{
		moves = ft_strdup("P1 Moves: ");
		moves = ft_strjoin_and_free(moves, moves_str);
		if (moves)
		{
			mlx_string_put(graphics->mlx, graphics->win, 15, 15,
				0xFFFFFF, moves);
			free(moves);
		}
		free(moves_str);
	}
}

void	ft_print_moves_p2(t_graphics *graphics, t_map *map, int win_width)
{
	char	*p2_moves_str;
	char	*p2_moves;

	p2_moves_str = ft_itoa(map->p2_moves);
	if (p2_moves_str)
	{
		p2_moves = ft_strdup("P2 Moves: ");
		p2_moves = ft_strjoin_and_free(p2_moves, p2_moves_str);
		if (p2_moves)
		{
			mlx_string_put(graphics->mlx, graphics->win, win_width - 100,
				15, 0xFFFFFF, p2_moves);
			free(p2_moves);
		}
		free(p2_moves_str);
	}
}
