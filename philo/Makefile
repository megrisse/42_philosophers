NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC = parse.c    philo.c routine.c  routine1.c utils.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean : 
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : 
	fclean all