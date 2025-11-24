/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:50:08 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/05 13:06:38 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	i = ft_strlen(s);
	cc = (char)c;
	while (s[i] != cc && i > 0)
	{
		i--;
	}
	if (s[i] == cc)
	{
		return ((char *)&s[i]);
	}
	else
		return (NULL);
}
