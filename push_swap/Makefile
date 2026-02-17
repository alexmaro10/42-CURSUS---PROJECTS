NAME = push_swap

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

SRCS = \
	src/push_swap.c \
	src/filter_arguments/atoi.c src/filter_arguments/split.c src/filter_arguments/split2_.c src/filter_arguments/filter.c src/filter_arguments/ft_is.c \
	src/ft_lst/control_lst.c src/ft_lst/control_lst2.c \
	src/moves/push.c src/moves/rev_rotate.c src/moves/rotate.c src/moves/swap.c \
	src/sort_function/small_arg.c src/sort_function/chunk_sort.c src/sort_function/chunk_sort_utils.c
	
INCLUDE = ./lib/push_swap.h

CC = cc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror

%.o: %.c
			@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))

all:	${NAME}

-include ${DEPS}
${NAME}: ${OBJS} $(INCLUDE)
	@${CC} ${SRCS} -o ${NAME}
	@echo "\n$(GREEN) Created $(NAME) ✓ $(DEF_COLOR)\n"


clean:
			@${RM} ${OBJS}
			@${RM} ${DEPS}
			@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"

fclean: 
			@${RM} ${OBJS}
			@${RM} ${DEPS}
			@${RM} ${NAME}
			@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re