/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:56:51 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/05 15:07:53 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	s1cpy = (unsigned char *) s1;
	s2cpy = (unsigned char *) s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1cpy[i] == s2cpy[i] && i < n - 1)
	{
		i++;
	}
	return (s1cpy[i] - s2cpy[i]);
}
