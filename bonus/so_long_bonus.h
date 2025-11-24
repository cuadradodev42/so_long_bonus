/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-23 15:07:30 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-23 15:07:30 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../Lib_ft/libft.h"
# include "../Lib_ft/Ft_printf/ft_printf.h"
# include "../Lib_ft/Get_Next_Line/get_next_line.h"
# include <stdbool.h>
# include <fcntl.h>

# define BACKGROUND '0'
# define WALL '1'
# define COLLECT 'C'
# define EXIT 'E'
# define PLAYER_START 'P'
# define ENEMY 'B'

typedef struct s_enemy
{
	int				x;
	int				y;
	int				dir;
	struct s_enemy	*next;
}	t_enemy;

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
	t_position	player2_pos;
	int			p1_collect;
	int			p2_collect;
	int			p2_moves;
	t_enemy		*enemies;
}	t_map;

typedef struct s_graphics
{
	void		*mlx;
	void		*win;
	void		*img_background;
	void		*img_wall;
	void		*img_collect;
	void		*img_exit;
	void		**img_player;
	void		**img_enemy;
	int			img_size;
	t_map		*map;
}	t_graphics;

void	ft_free2(char **str);
void	ft_free_map(char ***map);
void	ft_free_all(t_map *map);
void	ft_init_map(t_map *map);
void	ft_flood_fill(t_map *map, int x, int y);
void	ft_print_moves(t_graphics *graphics);
void	ft_print_moves_p1(t_graphics *graphics, t_map *map);
void	ft_print_moves_p2(t_graphics *graphics, t_map *map, int win_width);
void	ft_print_collectibles(t_graphics *graphics, t_map *map,
			int win_width, int win_height);
void	ft_print_collectibles_refresh(t_graphics *graphics, t_map *map);
void	ft_print_info(t_graphics *graphics);

void	ft_load_player_images(t_graphics *graphics);
void	ft_load_enemy_images(t_graphics *graphics);
void	ft_load_images(t_graphics *graphics);
void	ft_put_image(t_graphics *graphics, void *img, int x, int y);
void	ft_render_map(t_graphics *graphics, t_map *map);
void	ft_check_window_size(t_graphics *graphics, t_map *map);
int		ft_redraw_window(t_graphics *graphics);

void	ft_destroy_player_images(t_graphics *graphics);
void	ft_destroy_enemy_images(t_graphics *graphics);
int		ft_close_window(t_graphics *graphics);
void	ft_clear_old_pos(t_graphics *graphics);
void	ft_player_on_exit(t_graphics *graphics, int new_x, int new_y);

void	ft_put_image_direction(t_graphics *graphics, t_position old_pos,
			int new_x, int new_y);
void	ft_update_player_1(t_graphics *graphics, int new_x, int new_y);
void	ft_update_player_2(t_graphics *graphics, int new_x, int new_y);
int		ft_manage_keypress(int key, t_graphics *graphics);
void	ft_move_player_1(int key, t_graphics *graphics);
void	ft_move_player_2(int key, t_graphics *graphics);
void	ft_restore_old_pos_p2(t_graphics *graphics, int old_x, int old_y);
void	ft_check_collectible_p2(t_graphics *graphics, int new_x, int new_y);
void	ft_check_exit_p2(t_graphics *graphics, int new_x, int new_y);

void	ft_error_msg(char *msg, t_map *map);
void	ft_count_elements(t_map *map);
void	ft_check_transitable_map(t_map *map);
t_map	ft_duplicate_map(t_map *map);
void	ft_process_player_start(t_map *map, int i, int j);
void	ft_process_element(t_map *map, int i, int j);

void	ft_check_name_of_file(char *str);
void	ft_check_map(t_map *map);
void	ft_check_rectangular_map(t_map *map, char **line, int fd);
void	ft_checks(int *fd, t_map *map, char *str);
void	ft_validate_map(int fd, t_map *map);

void	ft_init_mlx(t_graphics *graphics);
void	ft_the_game(t_graphics *graphics, t_map *map);
void	ft_create_map(int fd, t_map *map);
void	ft_game(char *argv);

void	ft_clear_old_pos_player(t_graphics *graphics, t_map *map);
void	ft_clear_old_pos_player2(t_graphics *graphics, t_map *map);
void	ft_check_limits(t_map *map);
void	ft_init_enemies(t_map *map);
void	ft_add_enemy(t_map *map, int x, int y);
void	ft_free_enemies(t_enemy *enemies);
void	ft_move_enemys(t_graphics *graphics);
void	ft_put_enemys(t_graphics *graphics, t_map *map);
void	ft_put_enemy_rotating(t_graphics *graphics, int x, int y);
void	ft_put_players(t_graphics *graphics, t_map *map);

void	ft_destroy_images(t_graphics *graphics);
void	ft_close(t_graphics *graphics, char *msg);

#endif