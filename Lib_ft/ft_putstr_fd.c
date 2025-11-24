/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:56:07 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/19 17:21:03 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	lengt;
	size_t	i;

	lengt = ft_strlen(s);
	i = 0;
	while (i < lengt)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
