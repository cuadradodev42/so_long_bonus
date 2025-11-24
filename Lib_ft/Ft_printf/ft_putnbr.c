/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:10:42 by acuadrad          #+#    #+#             */
/*   Updated: 2025/06/09 11:50:28 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	lengt;
	int	c;

	lengt = 0;
	c = '0';
	if (nbr == -2147483648)
	{
		lengt += write(1, "-2147483648", 11);
		return (lengt);
	}
	if (nbr < 0)
	{
		lengt += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		lengt += ft_putnbr(nbr / 10);
	}
	c = nbr % 10 + '0';
	lengt += write(1, &c, 1);
	return (lengt);
}
