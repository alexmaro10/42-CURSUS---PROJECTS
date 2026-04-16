# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almaldon <almaldon@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 14:02:31 by chanin            #+#    #+#              #
#    Updated: 2025/09/14 09:16:25 by almaldon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

SRC = ft_isalpha.c ft_memcmp.c ft_strdup.c ft_strnstr.c ft_atoi.c \
		ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strrchr.c ft_bzero.c \
		ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c ft_calloc.c \
		ft_isprint.c ft_memset.c ft_strlen.c ft_toupper.c ft_isalnum.c \
		ft_memchr.c ft_strchr.c ft_strncmp.c ft_substr.c ft_strjoin.c  \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c GNL/get_next_line_bonus.c \
		GNL/get_next_line_utils_bonus.c ft_printf/ft_printf.c ft_printf/ft_printf_2.c \
		ft_free_stuff.c ft_chartostr.c ft_matrix.c ft_strjoin_var.c \
		ft_matrix_2.c

SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJ_DIR =  objects
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_B = $(SRC_B:%.c=$(OBJ_DIR)/%.o)

INCLUDE = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	
bonus: $(OBJ) $(OBJ_B)
	$(AR) $(NAME) $(OBJ) $(OBJ_B)
	
$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
fclean: 
	rm -rf $(NAME) $(OBJ_DIR)
	
re: fclean all

.PHONY: all bonus clean fclean re
