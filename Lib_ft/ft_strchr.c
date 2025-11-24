/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:34:24 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/05 12:46:31 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	i = 0;
	cc = (char)c;
	while (s[i] != cc && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == cc)
	{
		return ((char *)&s[i]);
	}
	else
		return (NULL);
}
