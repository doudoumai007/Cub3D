NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = \
	src/main.c \
	src/util.c \
	src/free.c \
	src/init_struct.c \
	src/parsing.c \
	src/texture.c \
	src/line.c \
	src/valid.c \


OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

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
