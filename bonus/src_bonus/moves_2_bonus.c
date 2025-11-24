/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-23 15:08:21 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-23 15:08:21 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_enemy_collision(t_graphics *graphics, int x, int y)
{
	t_enemy	*current;

	current = graphics->map->enemies;
	while (current)
	{
		if (current->x == x && current->y == y)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_update_player_1(t_graphics *graphics, int new_x, int new_y)
{
	t_map	*map;

	map = graphics->map;
	if (map->map[new_y][new_x] == WALL
		|| (new_x == map->player2_pos.x && new_y == map->player2_pos.y))
		return ;
	if (ft_check_enemy_collision(graphics, new_x, new_y))
	{
		ft_printf("Game over! Player 1 Fell Into The Black Hole!\n");
		ft_close_window(graphics);
	}
	ft_clear_old_pos_player(graphics, map);
	if (map->map[new_y][new_x] == COLLECT)
	{
		map->collect--;
		map->map[new_y][new_x] = BACKGROUND;
		map->p1_collect++;
	}
	ft_player_on_exit(graphics, new_x, new_y);
	ft_put_image_direction(graphics, map->pos, new_x, new_y);
	map->pos.x = new_x;
	map->pos.y = new_y;
	map->moves++;
	ft_print_info(graphics);
}

void	ft_update_player_2(t_graphics *graphics, int new_x, int new_y)
{
	t_map	*map;

	map = graphics->map;
	if (map->map[new_y][new_x] == WALL
		|| (new_x == map->pos.x && new_y == map->pos.y))
		return ;
	if (ft_check_enemy_collision(graphics, new_x, new_y))
	{
		ft_printf("Game over! Player 2 Fell Into The Black Hole!\n");
		ft_close_window(graphics);
	}
	ft_clear_old_pos_player2(graphics, map);
	if (map->map[new_y][new_x] == COLLECT)
	{
		map->collect--;
		map->map[new_y][new_x] = BACKGROUND;
		map->p2_collect++;
	}
	ft_player_on_exit(graphics, new_x, new_y);
	ft_put_image_direction(graphics, map->player2_pos, new_x, new_y);
	map->player2_pos.x = new_x;
	map->player2_pos.y = new_y;
	map->p2_moves++;
	ft_print_info(graphics);
}

void	ft_move_player_1(int key, t_graphics *graphics)
{
	int	new_x;
	int	new_y;

	new_x = graphics->map->pos.x;
	new_y = graphics->map->pos.y;
	if (key == 119)
		new_y--;
	else if (key == 115)
		new_y++;
	else if (key == 97)
		new_x--;
	else if (key == 100)
		new_x++;
	else
		return ;
	ft_update_player_1(graphics, new_x, new_y);
}

void	ft_move_player_2(int key, t_graphics *graphics)
{
	int	new_x;
	int	new_y;

	new_x = graphics->map->player2_pos.x;
	new_y = graphics->map->player2_pos.y;
	if (key == 65362)
		new_y--;
	else if (key == 65364)
		new_y++;
	else if (key == 65361)
		new_x--;
	else if (key == 65363)
		new_x++;
	else
		return ;
	ft_update_player_2(graphics, new_x, new_y);
}
