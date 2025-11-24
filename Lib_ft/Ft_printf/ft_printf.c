/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:59:42 by acuadrad          #+#    #+#             */
/*   Updated: 2025/06/14 20:20:32 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_format(const char *str, va_list args)
{
	if (*(str + 1) == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*(str + 1) == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*(str + 1) == 'p')
		return (ft_put_pointer(va_arg(args, unsigned long)));
	else if (*(str + 1) == 'd' || *(str +1) == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*(str + 1) == 'u')
		return (ft_put_unsigned_nbr(va_arg(args, unsigned int)));
	else if (*(str + 1) == 'x')
		return (ft_put_hex(va_arg(args, unsigned int)));
	else if (*(str + 1) == 'X')
		return (ft_put_mayus_hex(va_arg(args, unsigned long)));
	else if (*(str ++) == '%')
		return (write(1, "%%", 1));
	else
	{
		write(1, "Error\n", 6);
		return (-1);
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			size += ft_format(str, args);
			str++;
		}
		else
		{
			size += ft_putchar(*str);
		}
		str++;
	}
	va_end(args);
	return (size);
}
