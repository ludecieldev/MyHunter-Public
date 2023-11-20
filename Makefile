##
## EPITECH PROJECT, 2023
## B-MUL-100-LIL-1-1-myhunter-alexandre.garbe
## File description:
## Makefile
##

SRC	=	src/functions/screen_display.c	\
		src/main/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	+=	-W -Wall -Wextra

all:
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#
	rm -f *.o

re: fclean all

.PHONY:
	all clean fclean re
