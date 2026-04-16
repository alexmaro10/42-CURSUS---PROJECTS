# -------------------------------
# CONFIGURACIÓN
# -------------------------------

NAME        := cub3D
BONUS_NAME  := cub3D_bonus
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Iinclude -Ilibft -Iminilibx
OBJ_DIR     := obj
LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a
MLX_DIR     := minilibx
MLX_LIB     := $(MLX_DIR)/libmlx.a

# Todas las fuentes
SRCS	:=	src/main.c \
			src/parser/arg_validation.c \
			src/parser/map_validation.c \
			src/parser/map_validation_2.c \
			src/parser/map_validation_3.c \
			src/parser/map_limits.c \
			src/utils/utils.c \
			src/utils/utils_2.c \
			src/utils/utils_3.c \
			src/utils/utils_mlx.c \
			src/init/init.c \
			src/init/init_ray.c \
			src/raycast/raycast.c \
			src/loop/loop.c \
			src/movement/movement.c \
			src/movement/rotation.c \
			src/raycast/textures.c

BONUS_SRCS := src/main_bonus.c \
			src/parser/arg_validation_bonus.c \
			src/parser/map_validation_bonus.c \
			src/parser/map_validation_2_bonus.c \
			src/parser/map_validation_3_bonus.c \
			src/parser/map_limits_bonus.c \
			src/utils/utils_bonus.c \
			src/utils/utils_2_bonus.c \
			src/utils/utils_3_bonus.c \
			src/utils/utils_mlx_bonus.c \
			src/init/init_bonus.c \
			src/init/init_keys_bonus.c \
			src/init/init_ray_bonus.c \
			src/raycast/raycast_bonus.c \
			src/loop/loop_bonus.c \
			src/movement/movement_bonus.c \
			src/movement/rotation_bonus.c \
			src/movement/actions_bonus.c \
			src/raycast/textures_bonus.c \
			src/minimap/minimap_bonus.c \
			src/minimap/player_mm_bonus.c

# Generar nombres de objetos en obj/ manteniendo subcarpetas
OBJS        := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
BONUS_OBJS  := $(patsubst %.c,$(OBJ_DIR)/%.o,$(BONUS_SRCS))

# Flags para Linux
MLX_FLAGS   := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LDFLAGS     := $(LIBFT) $(MLX_FLAGS)

# -------------------------------
# COLORES
# -------------------------------

GREEN := \033[1;32m
WHITE := \033[1;37m
RESET := \033[0m

# -------------------------------
# OBJETIVO POR DEFECTO
# -------------------------------

all: $(LIBFT) $(MLX_LIB) $(NAME)

bonus: $(LIBFT) $(MLX_LIB) $(BONUS_NAME) 

# -------------------------------
# EJECUTABLE
# -------------------------------

$(NAME): $(OBJS)
	@printf "$(WHITE)Compilando $(NAME)...$(RESET)\t\t"
	@$(CC) $(OBJS) $(LDFLAGS) -o $@
	@printf "$(GREEN)[✔]$(RESET)\n\n"

$(BONUS_NAME): $(BONUS_OBJS)
	@printf "$(WHITE)Compilando $(BONUS_NAME)...$(RESET)\t\t"
	@$(CC) $(BONUS_OBJS) $(LDFLAGS) -o $@
	@printf "$(GREEN)[✔]$(RESET)\n\n"

# -------------------------------
# OBJETOS
# -------------------------------

# Compila cualquier .c en obj/ respetando subcarpetas
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: src/bonus/%.c
	@mkdir -p bonus
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# -------------------------------
# LIBFT
# -------------------------------

$(LIBFT):
	@printf "\n$(WHITE)Compilando libft...$(RESET)\t\t"
	@$(MAKE) -C $(LIBFT_DIR) --silent > /dev/null
	@printf "$(GREEN)[✔]$(RESET)\n"

# -------------------------------
# MINILIBX
# -------------------------------

$(MLX_LIB):
	@printf "$(WHITE)Compilando MiniLibX...$(RESET)\t\t"
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
	@printf "$(GREEN)[✔]$(RESET)\n"

# -------------------------------
# LIMPIEZA
# -------------------------------

clean:
	@printf "\n$(WHITE)[🧹] Limpiando objetos...$(RESET)\t"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent > /dev/null
	@$(MAKE) -C $(MLX_DIR) clean --silent > /dev/null
	@printf "$(GREEN)[✔]$(RESET)\n"

fclean: clean
	@printf "$(WHITE)[🧼] Eliminando ejecutable...$(RESET)\t"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent > /dev/null
	@$(MAKE) -C $(MLX_DIR) clean --silent > /dev/null
	@printf "$(GREEN)[✔]$(RESET)\n\n"

re: fclean all

.PHONY: all clean fclean re