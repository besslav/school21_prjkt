NAME	=	violence

HEAD	=	Weapon.hpp HumanA.hpp HumanB.hpp

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

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
