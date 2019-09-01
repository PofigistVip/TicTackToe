NAME=tickTackToe
SRC=main.cpp \
	TickTackToe.cpp
INCLUDE=-I include

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) $(INCLUDE) $(addprefix src/, $(SRC)) -lncurses -lstdc++

fclean:
	@rm -f $(NAME)

re: fclean all

cursor:
	@tput cnorm

.PHONY: all fclean re cursor