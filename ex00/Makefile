# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 12:57:26 by elise             #+#    #+#              #
#    Updated: 2023/04/17 16:11:01 by ecolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = btc

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

DEP = BitcoinExchange.hpp

%.o: %.cpp $(DEP)
	$(CC) $(CXXFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $^ -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all