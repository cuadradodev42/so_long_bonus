/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:43:31 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/19 12:41:36 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_number_lengt(int n)
{
	unsigned int	lengt;

	lengt = 1;
	if (n < 0)
	{
		lengt++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		lengt++;
	}
	return (lengt);
}

static char	*ft_converter(char *ascii, int n, unsigned int lengt)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		ascii[0] = '-';
		i++;
	}
	ascii[lengt] = '\0';
	while (i < lengt)
	{
		lengt--;
		ascii[lengt] = (char)((n % 10) + 48);
		n = n / 10;
	}
	return (ascii);
}

char	*ft_itoa(int n)
{
	unsigned int	lengt;
	char			*ascii;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	lengt = ft_number_lengt(n);
	ascii = malloc(sizeof(char) * (lengt + 1));
	if (!ascii)
		return (NULL);
	ascii = ft_converter(ascii, n, lengt);
	return (ascii);
}
