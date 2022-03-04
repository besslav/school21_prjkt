NAME = fdf
CC = gcc
HEAD	= fdf.h
GFLAGS =  -Wall -Wextra -Werror 
SRCS = 	fdf.c  drower.c events.c errors.c colors.c\
		includes/liba.c includes/get_next_line.c includes/get_next_line_utils.c\
		includes/ft_split.c



OBJ = ${SRCS:%.c=%.o}
OBJ_B = ${SRCS_B:%.c=%.o}


.PHONY: all clean fclean re bonus

all: ${NAME}

${NAME}: ${OBJ} ${HEAD}
	@${CC} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o	: %.c
	@${CC} -I mlx -c $< -o $@


clean:
	@rm -f ${OBJ} 

fclean: clean
	@rm -f ${NAME} 

re: fclean all 