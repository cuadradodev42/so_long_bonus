/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-25 14:40:44 by acuadrad          #+#    #+#             */
/*   Updated: 2025-11-25 14:40:44 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Error\nIncorrect number of arguments");
		exit (1);
	}
	ft_game(argv[1]);
	return (0);
}
