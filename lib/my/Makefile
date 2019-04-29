##
## EPITECH PROJECT, 2018
## makefile
## File description:
## mylib.a -> lib | my.h -> include
##

src	=	*.c

name	=	libmy.a

inc 	=	-I ../../include

$(name): $(src)
	gcc -c *.c $(inc)
	ar rc $(name) *.o

clean:
	rm -f *.o

fclean : clean
	rm -f $(name)

re : fclean all

all : $(name)
