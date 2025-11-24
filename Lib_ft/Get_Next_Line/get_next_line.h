/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:18:55 by acuadrad          #+#    #+#             */
/*   Updated: 2025/07/17 16:20:28 by acuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h> 
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

char			*get_next_line(int fd);
char			*ft_read_while_line(int fd, char *rest, char *buffer);
char			*ft_get_line(char *line);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin_s1free(char *str1, char *str2);
char			*ft_free(char *str);

#endif