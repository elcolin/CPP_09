# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 17:06:47 by ecolin            #+#    #+#              #
#    Updated: 2023/04/17 16:10:20 by ecolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = g++

CXXFLAGS = -g3 -fsanitize=address -std=c++98 -Wall -Wextra -Werror

SRC = PmergeMe.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf	$(NAME)

re: fclean all