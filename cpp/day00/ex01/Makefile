NAME	=	contact_book

HEAD	=	Contact.hpp ContactBook.hpp

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.cpp Contact.cpp PhoneBook.cpp

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
