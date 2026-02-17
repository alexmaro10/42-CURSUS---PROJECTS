NAME    := phoneBook
FLAGS   := -Wall -Werror -Wextra -std=c++98
SRC     := Contacts.cpp Phonebook.cpp main.cpp
CXX     := c++

# =========================
#         COLORS
# =========================
GREEN   := \033[0;32m
GREEN_N := \033[1;32m
RED     := \033[0;31m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
RESET   := \033[0m

# =========================
#         RULES
# =========================
all: $(NAME)

$(NAME): $(SRC)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	@$(CXX) $(FLAGS) $(SRC) -o $(NAME)
	@echo "$(GREEN)Compilation successful$(RESET)"
	@echo "$(BLUE)Executable generated: $(GREEN_N)$(NAME)$(RESET)"

clean:
	@echo "$(YELLOW)Removing temporary files...$(RESET)"
	@rm -rf $(NAME).dSYM
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