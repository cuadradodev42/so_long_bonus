/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:11:04 by acuadrad          #+#    #+#             */
/*   Updated: 2025/06/13 16:21:33 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr(unsigned int nbr)
{
	char		c;
	static int	lengt;

	c = '0';
	lengt = 1;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr >= 10)
	{
		ft_put_unsigned_nbr(nbr / 10);
		lengt++;
	}
	c = (nbr % 10) + '0';
	write (1, &c, 1);
	return (lengt);
}
