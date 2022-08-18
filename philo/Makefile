# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 22:09:50 by megrisse          #+#    #+#              #
#    Updated: 2022/08/18 20:34:06 by megrisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -g -Wall -Wextra -Werror

SRC = inits.c parse.c philos.c utils.c routine.c  

OBJ = $(SRC:.c=.o)

all : $(NAME)
		@echo "making philos"
		
$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean : 
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all
