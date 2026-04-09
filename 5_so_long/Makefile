NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = MLX42
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Iinclude -I$(LIBFT_DIR) -I$(MLX_DIR)/include

SRC = src/main.c src/utils.c src/map.c src/filter_map.c src/filter_map2.c src/player.c src/init.c src/render.c src/hook.c

BONUS_SRC = src/main_bonus.c src/utils_bonus.c src/map_bonus.c src/filter_map_bonus.c src/filter_map2_bonus.c src/player_bonus.c src/init_bonus.c src/render_bonus.c \
			src/hook_bonus.c src/animation_bonus.c src/enemy_bonus.c src/moves_bonus.c src/utils2_bonus.c src/animation_extra_bonus.c

OBJ = $(SRC:src/%.c=%.o)
BONUS_OBJ = $(BONUS_SRC:src/%.c=%.o)

# ========================
# FLAGS TO COMPILE ACCORDING TO SYSTEM
# ========================

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lm -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
	MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lm -lglfw -pthread
endif

# ========================
# RULES
# ========================

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIBFT)
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build
	@cmake --build $(MLX_DIR)/build
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME) $(MLX_FLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus/%.o: src/bonus/%.c
	@mkdir -p bonus
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	rm -rf $(MLX_DIR)/build
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re

