NAME = cub
CC = gcc
HEAD	= cub.h
GFLAGS =  -Wall -Wextra -Werror 
SRCS = 	cub.c \
		map_ways_colors.c map_size_collector.c map_init_validate.c map_get_colors.c\
		game_drow_start.c\
		errors_cleaners.c


OBJ = ${SRCS:%.c=%.o}
OBJ_B = ${SRCS_B:%.c=%.o}


.PHONY: all clean fclean re bonus

all: ft gnl mlx ${NAME}

${NAME}: ${OBJ} ${HEAD}
	@${CC}  ${OBJ} -L./libft -lft -L./get_next_line -lget_next_line -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o	: %.c ${HEAD}
	@${CC}  -I mlx -c $< -o $@

ft :
	@cd libft && make

gnl :
	@cd get_next_line && make

mlx :
	@cd mlx && make

clean:
	@cd libft && make clean
	@cd get_next_line && make clean
	@rm -rf ${OBJ} 

fclean: clean
	@rm -rf ${NAME}
	@cd libft && make fclean
	@cd get_next_line && make fclean

re: fclean all 