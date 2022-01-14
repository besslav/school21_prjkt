NAME = push_swap
CC = gcc
HEAD	= push_swap.h
GFLAGS =  -Wall -Wextra -Werror -I${HEAD}
SRCS = 	libft/ft_split.c libft/libs.c push_swap.c quick.c\
		print_mass.c stack_init/ft_lstinit.c libft/more_tools.c errors.c\
		stack_opers/swapers.c stack_opers/pushers.c stack_opers/rotate.c\
		algoritm.c algoritm2.c algo_push_back.c
		


OBJ = ${SRCS:%.c=%.o}


.PHONY: all clean fclean re bonus

all: ${NAME}

${NAME}: ${OBJ} ${HEAD}
	@${CC} ${OBJ}  

%.o	: %.c ${HEAD}
	@${CC}  -c $< -o $@

bonus	:
	@make all

clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all 

