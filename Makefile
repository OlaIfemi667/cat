##
## Personnal project, 2026
## cat
## File description:
## Makefile
##

SRC      =	$(shell echo src/*.c) \

OBJ     =       $(SRC:.c=.o)

NAME    =       cat

all:    $(NAME)

$(NAME):        $(OBJ)
	g++ -std=c++20 -Wall -Wextra -Werror $(SRC) -o $(NAME) -g3 -lcurl

clean:
	rm -f $(OBJ)
	rm -f *#
	rm -f *~
	rm -f log.save

fclean: clean
	rm -f $(NAME)

re:     fclean all
