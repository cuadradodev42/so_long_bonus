NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.
MLX_FLAGS = -lXext -lX11 -lm

SOURCE_DIR = ./src
OBJECT_DIR = obj
LIBFT_DIR = ./Lib_ft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ./Lib_ft/Ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
GET_NEXT_LINE_DIR = ./Lib_ft/Get_Next_Line
GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_DIR)/getnextline.a
MiniLibXDir = ./minilibx-linux
MiniLibXLib = $(MiniLibXDir)/libmlx.a

SRCS = $(SOURCE_DIR)/so_long.c\
	   $(SOURCE_DIR)/ft_aux.c \
	   $(SOURCE_DIR)/prev_check.c \
	   $(SOURCE_DIR)/next_check.c \
	   $(SOURCE_DIR)/graphics.c \
	   $(SOURCE_DIR)/moves.c \
	   $(SOURCE_DIR)/destroy_images.c \
	   $(SOURCE_DIR)/images.c

OBJS = $(SRCS:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/%.o)

all: $(LIBFT_LIB) $(GET_NEXT_LINE_LIB) $(MiniLibXLib) $(NAME)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "Libft compiled."

$(GET_NEXT_LINE_LIB):
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)
	@echo "Get_Next_Line compiled."

$(MiniLibXLib):
	@cd $(MiniLibXDir) && ./configure || true
	@$(MAKE) -C $(MiniLibXDir) libmlx.a
	@echo "MiniLibX compiled."

$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(GET_NEXT_LINE_LIB) $(MiniLibXLib) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(GET_NEXT_LINE_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MiniLibXLib) $(MLX_FLAGS)

clean:
	@rm -rf $(OBJECT_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	@$(MAKE) -C $(MiniLibXDir) clean
	@$(MAKE) -C ./bonus clean
	@echo "Cleaned object files."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean
	@$(MAKE) -C ./bonus fclean
	@echo "Removed executable."

re: fclean all

bonus: 
	@$(MAKE) --no-print-directory -C ./bonus 

.PHONY: all clean fclean re bonus