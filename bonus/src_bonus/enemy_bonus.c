/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-25 14:39:32 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-25 14:39:32 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_add_enemy(t_map *map, int x, int y)
{
	t_enemy	*new_enemy;
	t_enemy	*current;

	new_enemy = malloc(sizeof(t_enemy));
	if (!new_enemy)
	{
		ft_free_enemies(map->enemies);
		perror("Error\nMemory allocation failed");
		exit(1);
	}
	new_enemy->x = x;
	new_enemy->y = y;
	new_enemy->dir = 0;
	new_enemy->next = NULL;
	if (!map->enemies)
		map->enemies = new_enemy;
	else
	{
		current = map->enemies;
		while (current->next)
			current = current->next;
		current->next = new_enemy;
	}
}

void	ft_init_enemies(t_map *map)
{
	int	x;
	int	y;

	map->enemies = NULL;
	y = 0;
	while (y < map->dimensions.y)
	{
		x = 0;
		while (x < map->dimensions.x)
		{
			if (map->map[y][x] == ENEMY)
				ft_add_enemy(map, x, y);
			x++;
		}
		y++;
	}
}

void	ft_free_enemies(t_enemy *enemies)
{
	t_enemy	*tmp;

	while (enemies)
	{
		tmp = enemies;
		enemies = enemies->next;
		free(tmp);
	}
}

void	ft_put_image_direction(t_graphics *graphics, t_position old_pos,
	int new_x, int new_y)
{
	if (new_y < old_pos.y)
		ft_put_image(graphics, graphics->img_player[0], new_x, new_y);
	else if (new_y > old_pos.y)
		ft_put_image(graphics, graphics->img_player[1], new_x, new_y);
	else if (new_x < old_pos.x)
		ft_put_image(graphics, graphics->img_player[2], new_x, new_y);
	else if (new_x > old_pos.x)
		ft_put_image(graphics, graphics->img_player[3], new_x, new_y);
}
