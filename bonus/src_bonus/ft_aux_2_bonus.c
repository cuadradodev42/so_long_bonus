/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-23 12:52:07 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-23 12:52:07 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	ft_print_collectibles(t_graphics *graphics, t_map *map,
	int win_width, int win_height)
{
	char	*str;
	char	*temp;

	temp = ft_itoa(map->p1_collect);
	str = ft_strdup("P1 Collect: ");
	str = ft_strjoin_and_free(str, temp);
	free(temp);
	mlx_string_put(graphics->mlx, graphics->win, 15,
		win_height - 15, 0xFFFFFF, str);
	free(str);
	temp = ft_itoa(map->p2_collect);
	str = ft_strdup("P2 Collect: ");
	str = ft_strjoin_and_free(str, temp);
	free(temp);
	mlx_string_put(graphics->mlx, graphics->win,
		win_width - 100, win_height - 15, 0xFFFFFF, str);
	free(str);
}

void	ft_print_collectibles_refresh(t_graphics *graphics, t_map *map)
{
	int		win_width;
	int		win_height;

	win_width = map->dimensions.x * graphics->img_size;
	win_height = map->dimensions.y * graphics->img_size;
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, 0, win_height - 64);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, 64, win_height - 64);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, win_width - 64, win_height - 64);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, win_width - 128, win_height - 64);
	ft_print_collectibles(graphics, map, win_width, win_height);
}

void	ft_print_moves(t_graphics *graphics)
{
	t_map	*map;
	int		win_width;
	int		win_height;

	map = graphics->map;
	win_width = map->dimensions.x * graphics->img_size;
	win_height = map->dimensions.y * graphics->img_size;
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, 0, 0);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, 64, 0);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, win_width - 64, 0);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, win_width - 128, 0);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, 0, win_height - 64);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, 64, win_height - 64);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, win_width - 64, win_height - 64);
	mlx_put_image_to_window(graphics->mlx, graphics->win,
		graphics->img_wall, win_width - 128, win_height - 64);
	ft_print_moves_p1(graphics, map);
	ft_print_moves_p2(graphics, map, win_width);
}

void	ft_print_info(t_graphics *graphics)
{
	ft_print_moves(graphics);
	ft_print_collectibles_refresh(graphics, graphics->map);
}

void	ft_check_limits(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->dimensions.x)
	{
		if (map->map[0][i] != '1' || map->map[map->dimensions.y - 1][i] != '1')
		{
			ft_free_all(map);
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
			ft_free_all(map);
			perror("Error\nMap is not surrounded by walls");
			exit (1);
		}
		i++;
	}
}
