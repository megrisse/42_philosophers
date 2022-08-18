# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: megrisse <megrisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 22:09:50 by megrisse          #+#    #+#              #
#    Updated: 2022/08/18 23:19:34 by megrisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -g -Wall -Wextra -Werror
HEADER = philo.h

SRC = inits.c parse.c philos.c utils.c routine.c  

OBJ = $(SRC:.c=.o)

all : $(NAME)
		@echo "making philos"
		
$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean : 
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all
