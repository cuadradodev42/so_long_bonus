/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-23 16:14:44 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-23 16:14:44 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	ft_manage_keypress(int key, t_graphics *graphics)
{
	if (key == 65307)
		ft_close_window(graphics);
	ft_move_player_1(key, graphics);
	ft_move_player_2(key, graphics);
	ft_move_enemys(graphics);
	return (0);
}
