SRCS	= ft_display_file.c ft_putstr.c

OBJS	= ${SRCS:.c=.o}
NAME	= ft_display_file

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