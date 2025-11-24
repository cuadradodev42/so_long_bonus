/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 11:52:25 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-21 11:52:25 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_graphics *graphics)
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
	if (graphics->win)
		mlx_destroy_window(graphics->mlx, graphics->win);
	if (graphics->mlx)
	{
		mlx_destroy_display(graphics->mlx);
		free(graphics->mlx);
	}
	if (graphics->map)
		ft_free_map(&graphics->map->map);
	exit (0);
	return (0);
}

void	ft_clear_old_pos(t_graphics *graphics)
{
	t_map	*map;

	map = graphics->map;
	if (map->on_exit)
	{
		map->map[map->pos.y][map->pos.x] = EXIT;
		ft_put_image(graphics, graphics->img_exit, map->pos.x, map->pos.y);
		map->on_exit = 0;
	}
	else
	{
		map->map[map->pos.y][map->pos.x] = BACKGROUND;
		ft_put_image(graphics, graphics->img_background,
			map->pos.x, map->pos.y);
	}
}

void	ft_player_on_exit(t_graphics *graphics, int new_x, int new_y)
{
	t_map	*map;

	map = graphics->map;
	if (map->map[new_y][new_x] == EXIT)
	{
		if (map->collect == 0)
		{
			ft_printf("You win in %d moves.\n", map->moves + 1);
			ft_close_window(graphics);
		}
		else
			map->on_exit = 1;
	}
}

void	ft_move_player(t_graphics *graphics, int new_x, int new_y)
{
	t_map	*map;

	map = graphics->map;
	if (map->map[new_y][new_x] == WALL)
		return ;
	ft_clear_old_pos(graphics);
	if (map->map[new_y][new_x] == COLLECT)
		map->collect--;
	ft_player_on_exit(graphics, new_x, new_y);
	map->pos.x = new_x;
	map->pos.y = new_y;
	map->map[new_y][new_x] = PLAYER_START;
	ft_put_image(graphics, graphics->img_player, new_x, new_y);
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
}

int	ft_manage_keypress(int key, t_graphics *graphics)
{
	t_map	*map;
	int		new_x;
	int		new_y;

	map = graphics->map;
	new_x = map->pos.x;
	new_y = map->pos.y;
	if (key == 65307)
		ft_close_window(graphics);
	else if (key == 119)
		new_y--;
	else if (key == 115)
		new_y++;
	else if (key == 97)
		new_x--;
	else if (key == 100)
		new_x++;
	else
		return (0);
	ft_move_player(graphics, new_x, new_y);
	return (0);
}
