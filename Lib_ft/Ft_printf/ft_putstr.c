/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:09:29 by acuadrad          #+#    #+#             */
/*   Updated: 2025/06/09 15:17:36 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	size_t	lenght;

	lenght = 0;
	if (!str)
	{
		lenght += write(1, "(null)", 6);
	}
	while (str && *str != '\0')
	{
		lenght += write(1, str, 1);
		str++;
	}
	return (lenght);
}
