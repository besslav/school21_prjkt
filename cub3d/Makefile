NAME = cub
NAME_B = cub_b
CC = gcc
HEAD	= cub.h
GFLAGS =  -Wall -Wextra -Werror 
SRCS = 	cub.c \
		map_ways_colors.c map_size_collector.c map_init_validate.c map_is_close.c check_len_color.c\
		data_creator.c events.c\
		game_drow_start.c game_drow_fl_ceil.c game_utils.c game_wall_drow.c game_throw_rays.c game_get_ray.c\
		errors_cleaners.c\
		game_drow_minimap.c game_doors.c

SRCS_B = 	cub.c \
		map_ways_colors.c map_size_collector.c map_init_validate_b.c map_is_close.c check_len_color.c\
		data_creator.c events.c\
		game_drow_start.c game_drow_fl_ceil.c game_utils.c game_wall_drow.c game_throw_rays.c game_get_ray.c\
		errors_cleaners.c\
		game_drow_minimap.c game_doors.c


OBJ = ${SRCS:%.c=%.o}
OBJ_B = ${SRCS_B:%.c=%.o}


.PHONY: all clean fclean re bonus

all: ft gnl mlxx ${NAME}

bonus	: ft gnl mlxx ${NAME_B}

${NAME_B}:${OBJ_B} ${HEAD}
	@${CC} ${GFLAGS} ${OBJ_B} -L./libft -lft -L./get_next_line -lget_next_line -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

${NAME}: ${OBJ} ${HEAD}
	@${CC} ${GFLAGS} ${OBJ} -L./libft -lft -L./get_next_line -lget_next_line -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o	: %.c ${HEAD}
	@${CC} ${GFLAGS} -I mlx -c $< -o $@

ft :
	@cd libft && make

gnl :
	@cd get_next_line && make

mlxx :
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