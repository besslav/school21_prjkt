NAME	=	ex01

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror

HEAD	=	Span.hpp

SRCS	=	main.cpp Span.cpp

OBJS	=	${SRCS:.cpp=.o}

all		:	${NAME}

${NAME}	:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

%.o		:	%.cpp ${HEAD}
			${CC} ${FLAGS} -c $< -o $@

clean	:
			rm -f ${OBJS}

fclean	:	clean
			rm -f ${NAME}

re		:	fclean all
