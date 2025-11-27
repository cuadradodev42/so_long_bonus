/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:18:48 by acuadrad          #+#    #+#             */
/*   Updated: 2025/07/17 19:06:19 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	if (!s)
		return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_len;
	unsigned int	i;
	char			*substr;

	i = 0;
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start > s_len)
	{
		len = 0;
		start = s_len;
	}
	substr = malloc(len * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	while (s[i + start] != '\0' && i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin_s1free(char *str1, char *str2)
{
	size_t	i;
	size_t	str1_len;
	char	*strresult;

	if (!str1 && !str2)
		return (NULL);
	i = 0;
	str1_len = ft_strlen(str1);
	strresult = malloc((str1_len + ft_strlen(str2) + 1) * sizeof(char));
	if (!strresult)
		return (ft_free(str1));
	while (i < str1_len)
	{
		strresult[i] = str1[i];
		i++;
	}
	i = 0;
	while (str2[i] != 0)
	{
		strresult[i + str1_len] = str2[i];
		i++;
	}
	strresult[i + str1_len] = '\0';
	free(str1);
	return (strresult);
}
