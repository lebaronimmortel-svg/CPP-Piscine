SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
HEADER = Zombie.hpp HumanA.hpp HumanB.hpp Weapon.hpp
OBJ = $(SRC:.cpp=.o)
NAME = FightClub
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
