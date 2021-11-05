NAME = libftprintf.a
CC = gcc
HEAD	= ft_printf.h
GFLAGS = -Wall -Wextra -Werror -I${HEAD}
SRCS = 	ft_printf.c ft_printf_utils/ft_putstr_char.c\
ft_printf_utils/ft_putnbr_fd.c ft_printf_utils/ft_put_uns_nbr.c


OBJ = ${SRCS:%.c=%.o}


.PHONY: all clean fclean re bonus

all: ${NAME}

${NAME}: ${OBJ} ${HEAD}
	ar rcs ${NAME}  $?

%.o	: %.c ${HEAD}
	@${CC} ${GFLAGS} -c $< -o $@

clean:
	@rm -f ${OBJ} ${OBJ_B}

fclean: clean
	@rm -f ${NAME}

re: fclean all 


