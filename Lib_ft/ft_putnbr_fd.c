/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:01:52 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/20 21:48:05 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calculate_current_num(int n, int divider)
{
	n = n / divider;
	return (n);
}

static int	ft_get_divider(int n)
{
	int	divider;

	divider = 1;
	while (n > 9)
	{
		divider = divider * 10;
		n = n / 10;
	}
	return (divider);
}

static int	ft_handle_negative(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		divider;
	int		current_num;
	char	c;

	current_num = 0;
	c = '0';
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	n = ft_handle_negative(n, fd);
	divider = ft_get_divider(n);
	while (divider > 9)
	{
		current_num = ft_calculate_current_num(n, divider);
		c = current_num + '0';
		write (fd, &c, 1);
		n = n - (current_num * divider);
		divider = divider / 10;
	}
	current_num = ft_calculate_current_num(n, divider);
	c = current_num + '0';
	write (fd, &c, 1);
}
