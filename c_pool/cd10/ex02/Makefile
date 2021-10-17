SRCS	= ft_tail.c ft_putstr.c ft_atoi.c

OBJS	= ${SRCS:.c=.o}
NAME	= ft_tail

GCC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${GCC} ${CFAGS} -c $< -o ${<:.c=.o}

all:		${OBJS}
	${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

.PHONY:		all clean fclean