/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:13:09 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/19 12:37:45 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	new_str = malloc (s_len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s, s_len + 1);
	if (new_str && new_str[0] == 0)
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}
