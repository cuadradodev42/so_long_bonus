/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:29:47 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/04 18:56:12 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str_dest;

	str = (unsigned char *)src;
	str_dest = (unsigned char *)dest;
	if (src < dest)
	{
		while (n--)
			str_dest[n] = str[n];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (str_dest);
}
