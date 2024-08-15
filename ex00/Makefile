NAME = convert
FLAGS = -Werror -Wall -Wextra -std=c++98
CC = c++
SRC = main.cpp ScalarConverter.cpp

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: clean all

.PHONY: all clean fclean re
