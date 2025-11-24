/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:02:52 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/05 14:52:59 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*scpy;
	unsigned char	ccpy;

	scpy = (unsigned char *) s;
	ccpy = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (scpy[i] == ccpy)
		{
			return (&scpy[i]);
		}
		i++;
	}
	return (NULL);
}
