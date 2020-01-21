##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## build the lib
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strlen.c	\
		starts_with.c


OBJ	=	$(SRC:.c=.o)

MY	=	my.h

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ) $(SRC)
	@ar -crs $(NAME) $(OBJ)
	@cp $(NAME) ../

.PHONY: clean re fclean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re :	fclean all
