/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:03:19 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/02 22:29:02 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str_dest;

	i = 0;
	str = (unsigned char *)src;
	str_dest = (unsigned char *)dest;
	if (!src && !dest)
	{
		return (NULL);
	}
	while (i < n)
	{
		str_dest[i] = str[i];
		i++;
	}
	return (dest);
}
