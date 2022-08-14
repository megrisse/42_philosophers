NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror

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