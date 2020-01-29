##
## EPITECH PROJECT, 2019
## CPE_pushswap_2019
## File description:
## Makefile
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	=	src/main.c	\
			src/interpret.c	\
			src/built_in.c	\
			src/globalfunc.c	\
			src/setenv.c	\
			src/error.c

OBJS	= $(SRCS:.c=.o)

LIB = lib/libmy.a

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra
CFLAGS += -L./lib -lmy

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	@make -C lib/my clean --no-print-directory
	$(RM) $(OBJS)

$(LIB):
	@make -C lib/my --no-print-directory

fclean: clean
	@make -C lib/my fclean --no-print-directory
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re
