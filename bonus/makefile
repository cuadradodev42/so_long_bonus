NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I.
MLX_FLAGS = -lXext -lX11 -lm

SOURCE_DIR = ./src_bonus
OBJECT_DIR = obj/
LIBFT_DIR = ../Lib_ft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ../Lib_ft/Ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
GET_NEXT_LINE_DIR = ../Lib_ft/Get_Next_Line
GET_NEXT_LINE_LIB = $(GET_NEXT_LINE_DIR)/getnextline.a
MiniLibXDir = ../minilibx-linux
MiniLibXLib = $(MiniLibXDir)/libmlx.a

SRCS_COMMON = $(SOURCE_DIR)/ft_aux_bonus.c \
	   $(SOURCE_DIR)/ft_aux_2_bonus.c \
	   $(SOURCE_DIR)/prev_check_bonus.c \
	   $(SOURCE_DIR)/next_check_bonus.c \
	   $(SOURCE_DIR)/graphics_check_bonus.c \
	   $(SOURCE_DIR)/graphics_images_bonus.c \
	   $(SOURCE_DIR)/graphics_3_bonus.c \
	   $(SOURCE_DIR)/graphics_4_bonus.c \
	   $(SOURCE_DIR)/enemy_bonus.c \
	   $(SOURCE_DIR)/moves_1_bonus.c \
	   $(SOURCE_DIR)/moves_2_bonus.c \
	   $(SOURCE_DIR)/map_bonus.c \
	   $(SOURCE_DIR)/so_long_bonus.c \
	   $(SOURCE_DIR)/game_bonus.c \
	   $(SOURCE_DIR)/ft_clean_bonus.c \
	   $(SOURCE_DIR)/transitable_map.c \
	   $(SOURCE_DIR)/destroy_images.c

OBJS_COMMON = $(SRCS_COMMON:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/%.o)

all: $(LIBFT_LIB) $(GET_NEXT_LINE_LIB) $(MiniLibXLib) $(NAME) 

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c so_long_bonus.h
	@mkdir -p $(OBJECT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(GET_NEXT_LINE_LIB):
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

$(MiniLibXLib):
	@cd $(MiniLibXDir) && ./configure || true
	@$(MAKE) -C $(MiniLibXDir) libmlx.a

$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(GET_NEXT_LINE_LIB) $(MiniLibXLib) $(OBJS_COMMON)
	$(CC) $(CFLAGS) $(OBJS_COMMON) -o $(NAME) $(GET_NEXT_LINE_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MiniLibXLib) $(MLX_FLAGS)

clean:
	@rm -rf $(OBJECT_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) clean
	@$(MAKE) -C $(MiniLibXDir) clean

fclean: clean
	@rm -f $(NAME) $(NAME2)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

.PHONY: all clean fclean re