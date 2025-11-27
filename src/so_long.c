/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 11:38:05 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-21 11:38:05 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_the_game(t_graphics *graphics, t_map *map)
{
	ft_load_images(graphics);
	ft_check_window_size(graphics, map);
	ft_render_map(graphics, map);
	mlx_key_hook(graphics->win, ft_manage_keypress, graphics);
	mlx_hook(graphics->win, 17, 0, ft_close_window, graphics);
	mlx_loop(graphics->mlx);
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

int	main(int argc, char **argv)
{
	int			fd;
	t_map		map;
	t_graphics	graphics;

	if (argc != 2)
	{
		perror("Error\nIncorrect number of arguments");
		exit (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nIncorrect argument");
		exit (1);
	}
	ft_checks(&fd, &map, argv[1]);
	ft_init_mlx(&graphics);
	graphics.img_size = 64;
	graphics.map = &map;
	ft_the_game(&graphics, &map);
	ft_free_map(&map.map);
	return (0);
}
