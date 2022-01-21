NAME = push_swap
NAME_B = checker
CC = gcc
HEAD	= push_swap.h
GFLAGS =  -Wall -Wextra -Werror 
SRCS = 	libft/ft_split.c libft/libs.c libft/cleaners.c push_swap.c mass_initer.c quick.c\
		stack_init/ft_lstinit.c libft/more_tools.c errors.c algo_for_3_5.c\
		stack_opers/swapers.c stack_opers/pushers.c stack_opers/rotate.c\
		algoritm_best_combo.c algoritm_step_counter.c algo_push_back.c 
		
SRCS_B =  checker_gnl/get_next_line.c checker_gnl/checker_start.c\
		stack_opers/swapers.c stack_opers/pushers.c stack_opers/rotate.c\
		libft/ft_split.c libft/libs.c libft/cleaners.c libft/more_tools.c\
		mass_initer.c errors.c stack_init/ft_lstinit.c checker_gnl/get_next_line_utils.c



OBJ = ${SRCS:%.c=%.o}
OBJ_B = ${SRCS_B:%.c=%.o}


.PHONY: all clean fclean re bonus

all: ${NAME} ${NAME_B} 

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

