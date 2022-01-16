NAME = push_swap
CC = gcc
HEAD	= push_swap.h
GFLAGS =  -Wall -Wextra -Werror 
SRCS = 	libft/ft_split.c libft/libs.c libft/cleaners.c push_swap.c quick.c\
		stack_init/ft_lstinit.c libft/more_tools.c errors.c algo_for_3_5.c\
		stack_opers/swapers.c stack_opers/pushers.c stack_opers/rotate.c\
		algoritm.c algoritm2.c algo_push_back.c 
		


OBJ = ${SRCS:%.c=%.o}


.PHONY: all clean fclean re bonus

all: ${NAME}

${NAME}: ${OBJ} ${HEAD}
	@${CC} $(GFLAGS) ${OBJ} -o $(NAME)  

%.o	: %.c
	@${CC} ${GFLAGS}  -c $< -o $@

bonus	:
	@make all

clean:
	@rm -f ${OBJ}

fclean: clean
	@rm -f ${NAME}

re: fclean all 

