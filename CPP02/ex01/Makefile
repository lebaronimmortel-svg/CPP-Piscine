SRC = main.cpp Fixed.cpp
HEADER = Fixed.hpp
OBJ = $(SRC:.cpp=.o)
NAME = Fixed
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm

all: $(NAME)

$(NAME) : $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) -f $(OBJ)

fclean : clean
	$(RM) -f $(NAME)

re : fclean all

.PHONY: all fclean re
