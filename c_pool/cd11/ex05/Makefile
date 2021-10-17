SRCS	= do-op.c ft_atoi.c opers.c ft_putnbr.c

OBJS	= ${SRCS:.c=.o}
NAME	= do-op

GCC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		@${GCC} ${CFAGS} -c $< -o ${<:.c=.o}

all:		${OBJS}
		@${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean:		clean
		@${RM} ${NAME}

.PHONY:		all clean fclean