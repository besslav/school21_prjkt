SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

OBJS	= ${SRCS:.c=.o}
HEAD	= includes/ft.h
NAME	= libft.a

GCC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${GCC} ${CFAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc  ${NAME} ${OBJS} ${HEAD}

all:		${NAME}

clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
