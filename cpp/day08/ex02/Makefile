NAME	=	ex02

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.cpp

OBJS	=	${SRCS:.cpp=.o}

all		:	${NAME}

${NAME}	:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

%.o		:	%.cpp
			${CC} ${FLAGS} -c $< -o $@

clean	:
			rm -f ${OBJS}

fclean	:	clean
			rm -f ${NAME}

re		:	fclean all
