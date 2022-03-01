NAME = fdf
NAME_B = checker
CC = gcc
HEAD	= fdf.h
GFLAGS =  -Wall -Wextra -Werror 
SRCS = 	fdf.c \
		includes/liba.c includes/get_next_line.c includes/get_next_line_utils.c\
		includes/ft_split.c
		
SRCS_B =  includes/liba.c includes/get_next_line.c includes/get_next_line_utils.c



OBJ = ${SRCS:%.c=%.o}
OBJ_B = ${SRCS_B:%.c=%.o}


.PHONY: all clean fclean re bonus

all: ${NAME}

${NAME}: ${OBJ} ${HEAD}
	@${CC} $(GFLAGS) ${OBJ} -o $(NAME)

${NAME_B}: ${OBJ_B} ${HEAD}
	@${CC} $(GFLAGS) ${OBJ_B} -o $(NAME_B)

%.o	: %.c
	@${CC} ${GFLAGS}  -c $< -o $@

bonus	: ${NAME_B} 

clean:
	@rm -f ${OBJ} ${OBJ_B}

fclean: clean
	@rm -f ${NAME} ${NAME_B}

re: fclean all 