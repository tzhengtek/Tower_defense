##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefile
##

SRC     =	src/main.c\
			src/gestion_map.c\
			src/check/check_map.c\
			src/check/check_path.c\
			src/utils.c\
			src/game_window.c\
			src/create/create_window.c\
			src/create/create_sprite_linear.c\
			src/create/create_sprite_angle.c\
			src/check/check_next_pos.c\
			src/create/create_utils.c\
			src/create/create_path.c\
			src/utils2.c\
			src/utils3.c\
			src/check/check_angle.c\
			src/create/create_path_sprite.c\
			src/destroy/destroy.c\
			src/destroy/destroy2.c\
			src/create/create_map.c\
			src/create/create_mob.c\
			src/create/create_tower.c\
			src/create/create_utils2.c\
			src/display/display.c\
			src/display/display_game.c\
			src/display/display_rotate_mob.c\
			src/buttons/is_on_button.c\
			src/buttons/is_button_clicked.c\
			src/buttons/create_buttons.c\
			src/buttons/setup_buttons_1.c\
			src/buttons/setup_buttons_2.c\
			src/buttons/malloc_buttons.c\
			src/create/create_checkpoint.c\
			src/put_tower.c\
			src/event.c\
			src/move_mob.c\
			src/check/check_tower.c\
			src/utils4.c\
			src/buttons/setup_buttons_3.c\
			src/create/create_utils3.c\
			src/destroy/destroy3.c\
			src/attack_tower.c\
			src/attack_tower2.c

OBJ     =	$(SRC:.c=.o)

NAME    =	my_defender

TEST_NAME	=	unit_tests

CFLAGS	=	-Wall -Wextra

CPPFLAGS	= -I include

LDFLAGS	=	-L. -lmy -lcsfml-window\
-lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

all: 	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

debug: CPPFLAGS += -g3
debug: re

fclean: clean
	$(MAKE) fclean -C lib/my
	find . -size 0 -delete
	$(RM) $(NAME)

tests_run:	LDFLAGS += --coverage -lcriterion
tests_run:
	$(MAKE) -C lib/my
	$(CC) -o $(TEST_NAME) $(OBJ) $(LDFLAGS)
	./$(TEST_NAME)

re:	fclean all

.PHONY:	all clean fclean tests_run re debug
