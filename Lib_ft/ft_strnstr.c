/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:13:37 by acuadrad          #+#    #+#             */
/*   Updated: 2025/05/07 10:32:50 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	i_l;

	i = 0;
	i_l = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			while (big[i + i_l] == little[i_l] && i + i_l < len)
			{
				if (little[i_l +1] == '\0')
				{
					return ((char *)&big[i]);
				}
				i_l++;
			}
		}
		i++;
	}
	return (NULL);
}
