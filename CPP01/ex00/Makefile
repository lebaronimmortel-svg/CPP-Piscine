SRC = main.cpp randomChump.cpp newZombie.cpp Zombie.cpp
HEADER = Zombie.hpp
OBJ = $(SRC:.cpp=.o)
NAME = ZombieGenerator
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
