NAME = philosophers
CC = gcc
HEAD	= philo.h
GFLAGS =  -Wall -Wextra -Werror 
SRCS = 	philo.c live.c atoi.c



OBJ = ${SRCS:%.c=%.o}
OBJ_B = ${SRCS_B:%.c=%.o}


.PHONY: all clean fclean re bonus

all: ${NAME}

${NAME}: ${OBJ} ${HEAD}
	@${CC} $(GFLAGS) ${OBJ} -o $(NAME)

%.o	: %.c
	@${CC} ${GFLAGS}  -c $< -o $@


clean:
	@rm -f ${OBJ} 

fclean: clean
	@rm -f ${NAME} 

re: fclean all 