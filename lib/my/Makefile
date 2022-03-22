##
## EPITECH PROJECT, 2021
## Maekfile
## File description:
## makefile
##

SRC    	=	my_strlen.c	\
			my_strcmp.c	\
			open_file.c	\
			print_error.c\
			str_to_array.c\
			my_putarr.c\
			my_putstr.c\
			my_putchar.c\
			int_to_char.c\
			my_getnbr.c\
			my_compute_power_it.c

OBJ	=		$(SRC:.c=.o)

NAME	=	libmy.a

all:	libmy.a

libmy.a:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../..

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ../../$(NAME)

re:	fclean libmy.a
