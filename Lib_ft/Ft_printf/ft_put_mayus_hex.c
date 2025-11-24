/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_mayus_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:11:35 by acuadrad          #+#    #+#             */
/*   Updated: 2025/06/14 19:39:03 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_mayus_hex(unsigned int nbr)
{
	int		lengt;
	char	*hexkey;

	lengt = 0;
	hexkey = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		lengt += ft_put_mayus_hex(nbr / 16);
	}
	lengt += write(1, &hexkey[nbr % 16], 1);
	return (lengt);
}
