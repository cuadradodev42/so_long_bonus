/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:19:01 by acuadrad          #+#    #+#             */
/*   Updated: 2025/08/05 15:13:11 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

char	*ft_read_while_line(int fd, char *rest, char *buffer)
{
	char	*line;
	int		size;

	size = 1;
	if (rest)
	{
		line = ft_strdup(rest);
		free(rest);
	}
	else
		line = NULL;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (ft_free(line));
		buffer[size] = '\0';
		line = ft_strjoin_s1free(line, buffer);
		if (!line || line[0] == '\0')
			return (ft_free(line));
		if (ft_strchr(line, '\n') != NULL)
			break ;
	}
	return (line);
}

char	*ft_get_line(char *line)
{
	char	*result;
	size_t	size;

	if (!line)
		return (NULL);
	size = ft_strlen(line);
	if (ft_strchr(line, '\n') != NULL)
		result = ft_substr(line, 0, ft_strchr(line, '\n') - (char *)&line[0]
				+ 1);
	else
		result = ft_substr(line, 0, size);
	return (result);
}

char	*ft_get_rest(char *line)
{
	char	*result;
	char	*nl_ptr;

	if (!line)
		return (NULL);
	nl_ptr = ft_strchr(line, '\n');
	if (nl_ptr)
	{
		if (*(nl_ptr + 1) == '\0')
			return (NULL);
		result = ft_substr(line, (nl_ptr - line) + 1, ft_strlen(nl_ptr + 1));
	}
	else
		return (NULL);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > __INT_MAX__)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	temp = ft_read_while_line(fd, rest, buffer);
	free(buffer);
	rest = NULL;
	if (!temp)
		return (NULL);
	line = ft_get_line(temp);
	rest = ft_get_rest(temp);
	free(temp);
	if ((rest && rest[0] == 0))
		return (ft_free(rest));
	return (line);
}
