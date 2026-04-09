# -------------------------------
# CONFIGURACIÓN
# -------------------------------

NAME        := philo
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
OBJ_DIR     := obj

# -------------------------------
# ARCHIVOS FUENTE (NO wildcard)
# -------------------------------

SRCS        := main.c check_arg.c routines.c fork_manage.c death.c utils.c utils2.c

OBJS        := $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

# -------------------------------
# COLORES
# -------------------------------

GREEN := \033[1;32m
WHITE := \033[1;37m
RESET := \033[0m

# -------------------------------
# OBJETIVO POR DEFECTO
# -------------------------------

all: $(NAME)

# -------------------------------
# COMPILACIÓN DEL EJECUTABLE
# -------------------------------

$(NAME): $(OBJS)
	@printf "$(WHITE)Compilando $(NAME)...$(RESET)\t\t"
	@sleep 0.05
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)[✔]$(RESET)\n\n"
	@sleep 0.05
	@printf "\t$(GREEN)#######################################$(RESET)\n\n"
	@printf "\t\t$(GREEN)WELCOME TO PHILOSOPHERS$(RESET)\n\n"
	@printf "\t$(GREEN)#######################################$(RESET)\n\n"

# -------------------------------
# COMPILACIÓN DE OBJETOS
# -------------------------------

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# -------------------------------
# LIBFT
# -------------------------------

# -------------------------------
# LIMPIEZA
# -------------------------------

clean:
	@printf "\n$(WHITE)[🧹] Limpiando objetos...$(RESET)\t"
	@rm -rf $(OBJ_DIR)
	@sleep 0.05
	@printf "$(GREEN)[✔]$(RESET)\n"

fclean: clean
	@printf "$(WHITE)[🧼] Eliminando ejecutable...$(RESET)\t"
	@rm -f $(NAME)
	@sleep 0.05
	@printf "$(GREEN)[✔]$(RESET)\n\n"

re: fclean all

.PHONY: all clean fclean re