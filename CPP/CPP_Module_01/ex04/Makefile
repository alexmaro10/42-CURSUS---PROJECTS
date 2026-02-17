NAME	:= replacer
FLAGS	:= -Wall -Werror -Wextra -std=c++98
SRC	:= main.cpp
CXX := c++
OBJ_DIR := obj
OBJS	:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# =========================
#         COLORS
# =========================
GREEN   := \033[0;32m
RED     := \033[0;31m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
RESET   := \033[0m

# =========================
#         RULES
# =========================
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CXX) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation successful$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(FLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Removing temporary files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@sleep 0.4
	@echo "$(GREEN)Cleanup completed$(RESET)"

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@rm -rf $(NAME)
	@sleep 0.4
	@echo "$(GREEN)Executable removed$(RESET)"

re: fclean all
	@echo "$(BLUE)Project rebuilt successfully$(RESET)"

.PHONY: all clean fclean re