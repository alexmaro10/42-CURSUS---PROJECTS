NAME := ircserv
BNAME := ircserv_bonus

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRC :=	src/main.cpp \
		src/Server.cpp \
		src/User.cpp \
		src/UserManager.cpp \
		src/Channel.cpp \
		src/ChannelManager.cpp \
		src/CommandHandler.cpp \
		src/ErrorReplies.cpp \
		src/Message.cpp \
		src/commands/PassCommand.cpp \
		src/commands/NickCommand.cpp \
		src/commands/UserCommand.cpp \
		src/commands/PingCommand.cpp \
		src/commands/QuitCommand.cpp \
		src/commands/JoinCommand.cpp \
		src/commands/KickCommand.cpp \
		src/commands/PrivMsgCommand.cpp \
		src/commands/TopicCommand.cpp \
		src/commands/InviteCommand.cpp \
		src/commands/ModeCommand.cpp \

OBJ := $(SRC:.cpp=.o)

# ---------------BONUS--------------

BONUS_SRC :=	bonus/src/main.cpp \
				bonus/src/ServerBonus.cpp \
				bonus/src/UserBonus.cpp \
				bonus/src/UserManagerBonus.cpp \
				bonus/src/ChannelBonus.cpp \
				bonus/src/ChannelManagerBonus.cpp \
				bonus/src/CommandHandlerBonus.cpp \
				bonus/src/ErrorRepliesBonus.cpp \
				bonus/src/MessageBonus.cpp \
				bonus/src/commands/PassCommandBonus.cpp \
				bonus/src/commands/NickCommandBonus.cpp \
				bonus/src/commands/UserCommandBonus.cpp \
				bonus/src/commands/PingCommandBonus.cpp \
				bonus/src/commands/QuitCommandBonus.cpp \
				bonus/src/commands/JoinCommandBonus.cpp \
				bonus/src/commands/KickCommandBonus.cpp \
				bonus/src/commands/PrivMsgCommandBonus.cpp \
				bonus/src/commands/TopicCommandBonus.cpp \
				bonus/src/commands/InviteCommandBonus.cpp \
				bonus/src/commands/ModeCommandBonus.cpp \
				bonus/src/commands/BotCommandBonus.cpp \

BONUS_OBJ := $(BONUS_SRC:.cpp=.o)

RM := rm -f

GREEN := \033[1;32m
WHITE := \033[1;37m
RESET := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "\n$(GREEN)EXECUTABLE FILE $(NAME) CREATED!!$(RESET)\n"

bonus: CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -Ibonus/include -g
bonus: $(BONUS_OBJ)
	@$(CXX) $(CXXFLAGS) $(BONUS_OBJ) -o $(BNAME)
	@echo "\n$(GREEN)BONUS BUILD DONE$(RESET)\n"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)$<$(RESET) compiled."

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)
		@echo "\nObjects cleaned."

fclean: clean
	@$(RM) $(NAME) $(BNAME)
	@echo "Executable cleaned.\n"

re: fclean all

.PHONY: all clean fclean re