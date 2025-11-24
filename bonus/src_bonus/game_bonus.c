/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-23 12:48:27 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-23 12:48:27 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_game_struct(t_graphics *graphics, t_map *map)
{
	ft_init_mlx(graphics);
	graphics->img_size = 64;
	graphics->map = map;
}

void	ft_game(char *argv)
{
	int			fd;
	t_map		map;
	t_graphics	graphics;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nIncorrect argument");
		exit (1);
	}
	ft_checks(&fd, &map, argv);
	ft_init_enemies(&map);
	init_game_struct(&graphics, &map);
	ft_the_game(&graphics, &map);
	ft_free_all(&map);
}

int	ft_redraw_window(t_graphics *graphics)
{
	ft_render_map(graphics, graphics->map);
	ft_print_info(graphics);
	return (0);
}

void	ft_init_mlx(t_graphics *graphics)
{
	graphics->mlx = mlx_init();
	if (!graphics->mlx)
	{
		perror("Error\nFailed to initialize MLX\n");
		exit (1);
	}
	graphics->img_background = NULL;
	graphics->img_wall = NULL;
	graphics->img_collect = NULL;
	graphics->img_exit = NULL;
	graphics->img_player = NULL;
	graphics->win = NULL;
	graphics->img_enemy = NULL;
	graphics->map = NULL;
	graphics->img_size = 0;
}

void	ft_the_game(t_graphics *graphics, t_map *map)
{
	ft_load_images(graphics);
	ft_check_window_size(graphics, map);
	ft_render_map(graphics, map);
	mlx_key_hook(graphics->win, ft_manage_keypress, graphics);
	mlx_hook(graphics->win, 17, 0, ft_close_window, graphics);
	mlx_hook(graphics->win, 12, 1L << 15, ft_redraw_window, graphics);
	mlx_loop(graphics->mlx);
}
