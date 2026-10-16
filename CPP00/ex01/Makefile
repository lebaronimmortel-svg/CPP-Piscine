# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 17:24:50 by alexfuen          #+#    #+#              #
#    Updated: 2026/01/18 17:24:52 by alexfuen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = Main.cpp Contact_Functions.cpp PhoneBook_Functions.cpp Utils_Functions.cpp
OBJ = $(SRC:.c=.o)
HEADERS = Contact.hpp PhoneBook.hpp Header.hpp 
NAME = PhoneBook
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
