# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 19:00:00 by acuadrad          #+#    #+#              #
#    Updated: 2025/10/19 15:21:55 by acuadrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = \
			ft_printf.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_put_pointer.c\
			ft_putnbr.c\
			ft_put_unsigned_nbr.c\
			ft_put_hex.c\
			ft_put_mayus_hex.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -r $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
