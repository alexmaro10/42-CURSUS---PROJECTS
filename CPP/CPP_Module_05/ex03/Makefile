NAME	:= ex02
FLAGS	:= -Wall -Werror -Wextra -std=c++98
SRC	:=	src/main.cpp \
		src/Bureaucrat.cpp \
		src/AForm.cpp \
		src/ShrubberyCreationForm.cpp \
		src/RobotomyRequestForm.cpp \
		src/PresidentialPardonForm.cpp \
		src/Intern.cpp
CXX := c++
OBJ_DIR := obj
OBJS	:= $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)

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

$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(FLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Removing temporary files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removing shrubbery file...$(RESET)"
	@rm -rf *_shrubbery
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