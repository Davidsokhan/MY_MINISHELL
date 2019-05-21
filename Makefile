##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC =   main.c \
        src/print.c \
        src/count.c \
        src/minishell.c \
        src/my_chdir.c \
        src/my_clean.c \
        src/my_env.c \
        src/my_exec.c \
        src/my_fork.c \
        src/my_path.c \
        src/to_word_array.c \
        src/unset_env.c \
        src/word_array.c

NAME =  mysh

CFLAGS = -Wall -Wextra -Werror


all:    $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(CFLAGS)
	@echo "all done"
clean:
	rm -f $(NAME)
	@echo "all clean"

fclean:	clean

re: $(NAME)