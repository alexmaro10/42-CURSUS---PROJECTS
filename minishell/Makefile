# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanin <chanin@student.42malaga.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 14:02:31 by chanin            #+#    #+#              #
#    Updated: 2025/09/17 10:59:44 by chanin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

#NAME_bonus = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g 
LDFLAGS = -lreadline -lncurses


SRC = 	minishell_main.c minishell_quotes.c minishell_split.c \
		minishell_expand.c minishell_built_in_1.c \
		minishell_built_in_2.c minishell_built_in_3.c \
		minishell_signals.c minishell_expand_aux.c \
		minishell_quotes_bis.c utils.c utils2.c minishell_exec.c \
		minishell_parser.c minishell_run_command.c minishell_run_built_in.c \
		minishell_parser_2.c minishell_find_comand.c minishell_redirections.c \
		minishell_main_main.c

#SRC_B  = 

OBJ_DIR =  objects
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
#OBJ_B = $(SRC_B:%.c=$(OBJ_DIR)/%.o)

LIBFT = libft/libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) $(LDFLAGS)
	@echo "\n                    -------------------------\n                        MINISHELL COMPILED\n                    -------------------------\n"

#$(NAME_bonus): $(OBJ_B) $(LIBFT)
#	$(CC) $(CFLAGS) $(OBJ_B) $(LIBFT) -o $(NAME_bonus)
#	@echo "\n                    -------------------------\n                      YOU ARE THE LECHE !!!\n                    -------------------------\n"

$(LIBFT):
	@echo "Compilando libft..."
	@$(MAKE) -C libft bonus > /dev/null
	
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

#bonus: $(NAME_bonus)

clean:
	rm -rf $(OBJ_DIR)
#	rm -f $(NAME_bonus)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) 
#	rm -f $(NAME_bonus) 
	$(MAKE) -C libft fclean
	
re: fclean all

.PHONY: all clean fclean re bonus
