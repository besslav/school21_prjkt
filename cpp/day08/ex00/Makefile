NAME	=	ex00

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror

HEAD	=	easyfind.hpp

SRCS	=	main.cpp

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
