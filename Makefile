SOURCE =  pipex_utils.c split.c pipex.c

RM = rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SOURCE:.c=.o)

AR = ar rc

NAME = pipex

%.o: %.c pipex.h
	$(CC)  $(CFLAGS) -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
all: $(NAME)
 
clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all