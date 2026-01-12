NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = \
	src/parsing/main.c \
	src/parsing/util.c \
	src/parsing/free.c \
	src/parsing/init_struct.c \
	src/parsing/parsing.c \
	src/parsing/texture.c \
	src/parsing/line.c \
	src/parsing/valid.c \
	src/parsing/player.c \
	src/parsing/parse_map.c \
	src/parsing/check_texture.c \
	src/parsing/debug.c \
	src/window/create_window.c \

OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: src/%.c
	mkdir -p $(OBJ_DIR)/src
#$(OBJ_DIR)/raycasting $(OBJ_DIR)/window $(OBJ_DIR)/parse
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
