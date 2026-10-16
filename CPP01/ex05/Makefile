SRC = main.cpp Harl.cpp
OBJ = $(SRC:.c=.o)
HEADERS = Harl.hpp
NAME = Harl
CFLAGS = -Wall -Wextra -Werror -lreadline -g -std=c++98
RM = rm

all: $(NAME)

$(NAME) : $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(NAME)
	
%.o:%.c $(HEADERS)
	c++ $(CFLAGS) $< -o $@

fclean :
	$(RM) -f $(NAME)

re : fclean all

.PHONY: all fclean re