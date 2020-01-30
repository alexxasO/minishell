##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## build the lib
##

ECHO =		/bin/echo -e
DEFAULT =	"\033[00m"
GREEN =		"\033[0;32m"
BGREEN =	"\033[1;32m"
TEAL =		"\033[1;36m"
RED =		"\033[0;31m"
BRED =		"\033[1;31m"

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strlen.c	\
		starts_with.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_explode.c	\
		my_strdup.c	\
		str_contain.c


OBJ	=	$(SRC:.c=.o)

CFLAGS = -g

MY	=	my.h

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ) $(SRC)
	@ar -crs $(NAME) $(OBJ)
	@cp $(NAME) ../

.PHONY: clean re fclean

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re :	fclean all

.c.o:
		@gcc $(CFLAGS) -c -o $@ $^ && $(ECHO) \
		$(BGREEN)"[OK]"$(TEAL) `basename $^` $(DEFAULT) \
		|| $(ECHO) $(BRED)"[ERROR]"$(TEAL) $< $(DEFAULT)
