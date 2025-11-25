/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-25 14:40:37 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-25 14:40:37 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		ft_error_msg("Error\nNo collectibles in the map", map);
	if (map->exit != 1)
		ft_error_msg("Error\nThe map must have exactly one exit", map);
	if (map->players != 2)
		ft_error_msg("Error\nInvalid number of player in the map", map);
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
		ft_error_msg("Error\nMap is not rectangular", map);
		exit(1);
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
	ft_check_limits(map);
	ft_check_map(map);
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
