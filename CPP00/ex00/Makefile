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
