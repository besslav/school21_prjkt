NAME = pipex
NAME_B = next_lvl_pipex
CC = gcc
HEAD	= pipex.h
GFLAGS =  -Wall -Wextra -Werror 
SRCS = 	pipex.c utils.c\
		liba/ft_libs.c liba/ft_split.c
		
SRCS_B = pipex_bonus.c utils_bonus.c\
		liba/ft_libs.c liba/ft_split.c 



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

