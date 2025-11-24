# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuadrad <acuadrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 10:58:48 by acuadrad          #+#    #+#              #
#    Updated: 2025/05/20 22:19:12 by acuadrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = \
		ft_isalnum.c\
		ft_bzero.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memset.c\
		ft_strlen.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_striteri.c\
		ft_strmapi.c\
		ft_strcmp.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = Ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(PRINTF_LIB):
	@echo "Compilando printf..."
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJECTS) $(PRINTF_LIB)
	@echo "Creando libreria libft.a (incluyendo ft_printf)..."
	@ar rcs $(NAME) $(OBJECTS)
	@ar x $(PRINTF_LIB)
	@ar rcs $(NAME) $(OBJECTS) *.o
	@rm -f *.o

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(PRINTF_DIR) clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
