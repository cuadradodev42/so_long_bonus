/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:06:36 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/10 16:44:29 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc_mem;

	alloc_mem = malloc(nmemb * size);
	if (!alloc_mem)
		return (NULL);
	ft_bzero(alloc_mem, nmemb * size);
	return (alloc_mem);
}
