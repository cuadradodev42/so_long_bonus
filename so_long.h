/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-21 11:44:45 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-21 11:44:45 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "Lib_ft/libft.h"
# include "Lib_ft/Ft_printf/ft_printf.h"
# include "Lib_ft/Get_Next_Line/get_next_line.h"
# include <stdbool.h>
# include <fcntl.h>

# define BACKGROUND '0'
# define WALL '1'
# define COLLECT 'C'
# define EXIT 'E'
# define PLAYER_START 'P'
# define ENEMY 'B'

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	t_position	dimensions;
	t_position	pos;
	char		**map;
	int			exit;
	int			collect;
	int			moves;
	int			players;
	int			on_exit;
}	t_map;

typedef struct s_graphics
{
	void		*mlx;
	void		*win;
	void		*img_background;
	void		*img_wall;
	void		*img_collect;
	void		*img_exit;
	void		*img_player;
	int			img_size;
	t_map		*map;
}	t_graphics;

void	ft_create_map(int fd, t_map *map);
void	ft_init_map(t_map *map);
void	ft_map_error(t_map *map, char **line);
void	ft_validate_map(int fd, t_map *map);
void	ft_free_map(char ***map);
void	ft_free2(char **str);
void	ft_check_map(t_map *map);
void	ft_check_rectangular_map(t_map *map, char **line, int fd);
void	ft_flood_fill(t_map *map, int x, int y);
void	ft_check_transitable_map(t_map *map);
void	ft_init_mlx(t_graphics *graphics);
void	ft_check_window_size(t_graphics *graphics, t_map *map);
void	ft_checks(int *fd, t_map *map, char *str);
t_map	ft_duplicate_map(t_map *map);
int		ft_close_window(t_graphics *graphics);
void	ft_load_images(t_graphics *graphics);
void	ft_put_image(t_graphics *graphics, void *img, int x, int y);
void	ft_render_map(t_graphics *graphics, t_map *map);
int		ft_manage_keypress(int key, t_graphics *graphics);
void	ft_move_player(t_graphics *graphics, int new_x, int new_y);
void	ft_count_elements(t_map *map);
void	ft_check_name_of_file(char *str);
void	ft_player_on_exit(t_graphics *graphics, int new_x, int new_y);
void	ft_the_game(t_graphics *graphics, t_map *map);
void	ft_check_limits(t_map *map);
void	ft_game(char *argv);
void	ft_print_info(t_graphics *graphics);
void	ft_destroy_images(t_graphics *graphics);
void	ft_close(t_graphics *graphics, char *message);

#endif