NAME = getnextline.a
SOURCES = \
			get_next_line_utils.c\
			get_next_line.c
			
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