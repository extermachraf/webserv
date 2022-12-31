NAME = parser
CC = c++
SRC = main.cpp \
	read_from_conf.cpp \
	Holder.cpp \
	./classes/Server_locatiation.cpp \
	parse.cpp
FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
ARG = -o
all : $(NAME)
$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) $(ARG) $(NAME)
clean :
	rm -rf $(NAME) *.dSYM
fclean : clean

re: fclean all
