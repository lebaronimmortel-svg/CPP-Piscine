SRC = megaphone.cpp
NAME = megaphone
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm

all: $(NAME)

$(NAME) : $(SRC)
	c++ $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	$(RM) -f $(NAME)

re : fclean all

.PHONY: all fclean re
