/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:11:15 by acuadrad          #+#    #+#             */
/*   Updated: 2025/06/14 20:14:01 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long nbr)
{
	int		lengt;
	char	*hexkey;

	lengt = 0;
	hexkey = "0123456789abcdef";
	if (nbr >= 16)
	{
		lengt += ft_put_hex(nbr / 16);
	}
	lengt += write(1, &hexkey[nbr % 16], 1);
	return (lengt);
}
