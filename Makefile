##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

SRC_DIR	=	src/
LIB_DIR	=	lib/my/
INC_DIR	=	include/
TESTS_DIR	=	tests/

NAME	=	mysh

CFLAGS	=  -g3 -Werror -Wall -Wextra -I $(INC_DIR) $(LDFLAGS)

LDFLAGS	=	-L $(LIB_DIR) -lmy

DFLAGS = -g3 $(CFLAGS)

SRC	=	$(SRC_DIR)minishell.c \
		$(SRC_DIR)cd.c \
		$(SRC_DIR)prompt.c \
		$(SRC_DIR)testing_file.c \
		$(SRC_DIR)clean_buffer.c \
		$(SRC_DIR)env.c \
		$(SRC_DIR)unsetenv.c \
		$(SRC_DIR)check_status.c \
		$(SRC_DIR)update_env.c \
		$(SRC_DIR)search.c \
		$(SRC_DIR)redirections.c \
		$(SRC_DIR)exec.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:	$(NAME)

# `make` normal
$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

# `make clean` clean lib/*.o + projet
clean:
	make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

# `make clean` clean + binary/library
fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

debug: fclean $(OBJ)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJ) $(DFLAGS)

re:	fclean all

.PHONY: all clean fclean re
