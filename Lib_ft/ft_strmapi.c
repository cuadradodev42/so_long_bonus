/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:43:14 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/20 20:50:34 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	s_len;
	char			*s_copy;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	s_copy = malloc ((s_len + 1) * sizeof(char));
	if (!s_copy)
		return (NULL);
	ft_strlcpy(s_copy, s, s_len);
	while (s[i] != '\0')
	{
		s_copy[i] = f(i, s[i]);
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
