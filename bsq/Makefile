GCC = gcc
GFLAGS = -Wall -Wextra -Werror
FC = main.c ft_split.c ft_strlen.c map_error.c map_creator.c n_to_0.c alg2.c
FO = ${FC:.c=.o}
NAME = bsq

.c.o:
	@${GCC} ${GFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${FO}
	@${GCC} ${GFLAGS} -o ${NAME} ${FO}

clean:
	@rm -f ${FO}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
