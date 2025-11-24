/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 16:31:59 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-21 16:31:59 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_name_of_file(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 5 || !(str[len - 4] == '.' && str[len - 3] == 'b'
			&& str[len - 2] == 'e' && str[len - 1] == 'r'))
	{
		perror("Error\nInvalid file extension");
		exit (1);
	}
}

void	ft_check_map(t_map *map)
{
	ft_count_elements(map);
	if (map->collect == 0)
	{
		ft_free_map(&map->map);
		perror("Error\nNo collectibles in the map");
		exit (1);
	}
	if (map->exit != 1)
	{
		ft_free_map(&map->map);
		perror("Error\nNo exit in the map");
		exit (1);
	}
	if (map->players != 1)
	{
		ft_free_map(&map->map);
		perror("Error\nInvalid number of players in the map");
		exit (1);
	}
}

void	ft_check_rectangular_map(t_map *map, char **line, int fd)
{
	int	len;

	len = ft_strlen(*line);
	if (len > 0 && (*line)[len - 1] == '\n')
		len--;
	if (map->dimensions.x != len)
	{
		ft_free2(line);
		ft_free_map(&map->map);
		while (1)
		{
			*line = get_next_line(fd);
			if (!*line)
				break ;
			free(*line);
		}
		perror("Error\nNon-rectangular map");
		exit (1);
	}
}

void	ft_checks(int *fd, t_map *map, char *str)
{
	ft_check_name_of_file(str);
	ft_init_map(map);
	ft_validate_map(*fd, map);
	close(*fd);
	*fd = open(str, O_RDONLY);
	if (*fd < 0)
	{
		perror("Error\nIncorrect argument");
		exit (1);
	}
	ft_create_map(*fd, map);
	ft_check_map(map);
	ft_check_limits(map);
	ft_check_transitable_map(map);
}

void	ft_validate_map(int fd, t_map *map)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
	{
		perror("Error\nEmpty map");
		exit (1);
	}
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	map->dimensions.x = len;
	map->dimensions.y = 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_check_rectangular_map(map, &line, fd);
		map->dimensions.y++;
	}
	ft_free2(&line);
}
