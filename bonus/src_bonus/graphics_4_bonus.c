/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_4_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 11:11:51 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-24 11:11:51 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_enemy_rotating(t_graphics *graphics, int x, int y)
{
	static int	i = 0;

	ft_put_image(graphics, graphics->img_enemy[i], x, y);
	i++;
	if (i > 3)
		i = 0;
}

static void	ft_update_enemy_pos(t_graphics *graphics, t_enemy *enemy,
	int nx, int ny)
{
	if ((nx == graphics->map->pos.x && ny == graphics->map->pos.y))
	{
		ft_printf("Player 1 Fell Into The Black Hole!\n");
		ft_close_window(graphics);
	}
	if ((nx == graphics->map->player2_pos.x
			&& ny == graphics->map->player2_pos.y))
	{
		ft_printf("Player 2 Fell Into The Black Hole!\n");
		ft_close_window(graphics);
	}
	if (graphics->map->map[enemy->y][enemy->x] == 'C')
		ft_put_image(graphics, graphics->img_collect, enemy->x, enemy->y);
	else if (graphics->map->map[enemy->y][enemy->x] == 'E')
		ft_put_image(graphics, graphics->img_exit, enemy->x, enemy->y);
	else
		ft_put_image(graphics, graphics->img_background, enemy->x, enemy->y);
	enemy->x = nx;
	enemy->y = ny;
	ft_put_enemy_rotating(graphics, nx, ny);
}

void	ft_process_enemy_move(t_graphics *graphics, t_enemy *enemy)
{
	int	nx;
	int	ny;

	nx = enemy->x;
	ny = enemy->y;
	if (enemy->dir == 0)
		ny--;
	else if (enemy->dir == 1)
		ny++;
	else if (enemy->dir == 2)
		nx--;
	else if (enemy->dir == 3)
		nx++;
	if (graphics->map->map[ny][nx] != '1' && graphics->map->map[ny][nx] != 'E')
		ft_update_enemy_pos(graphics, enemy, nx, ny);
	else
	{
		enemy->dir++;
		if (enemy->dir > 3)
			enemy->dir = 0;
		ft_put_enemy_rotating(graphics, enemy->x, enemy->y);
	}
}

void	ft_move_enemys(t_graphics *graphics)
{
	t_enemy	*current;

	current = graphics->map->enemies;
	while (current)
	{
		ft_process_enemy_move(graphics, current);
		current = current->next;
	}
}
