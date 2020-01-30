##
## EPITECH PROJECT, 2019
## PSU_minishell1_2019
## File description:
## Makefile
##

ECHO =		/bin/echo -e
DEFAULT =	"\033[00m"
GREEN =		"\033[0;32m"
BGREEN =		"\033[1;32m"
TEAL =		"\033[1;36m"
ORANGE =	"\e[1;33m"
RED =		"\033[0;31m"
BRED =		"\033[1;31m"

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	=	src/main.c	\
			src/interpret.c	\
			src/built_in.c	\
			src/globalfunc.c	\
			src/setenv.c	\
			src/error.c	\
			src/run_from_env.c	\
			src/cd_setenv.c 	\
			src/signals.c

OBJS	= $(SRCS:.c=.o)

LIB = lib/libmy.a

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra
CFLAGS += -L./lib -lmy

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	@make -C lib/my clean --no-print-directory
	@$(RM) $(OBJS)
	@$(ECHO) $(ORANGE) "clean"

$(LIB):
	@make -C lib/my --no-print-directory

fclean: clean
	@make -C lib/my fclean --no-print-directory
	@$(RM) $(NAME)
	@$(ECHO) $(ORANGE) "fclean"

re: fclean all

debug: CFLAGS += -g
debug: re
		@$(ECHO) $(BRED) "Debug mode"

.PHONY: all clean fclean re

.c.o:
		@gcc $(CFLAGS) -c -o $@ $^ && $(ECHO) \
		$(GREEN)"[OK]"$(TEAL) $< $(DEFAULT) \
		|| $(ECHO) $(RED)"[ERROR]"$(TEAL) $< $(DEFAULT)