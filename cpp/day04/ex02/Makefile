NAME	=	animals

FC		=	main.cpp	AAnimal.cpp	Cat.cpp	Dog.cpp Brain.cpp
FO		=	$(FC:%.cpp=%.o)
FH		=	AAnimal.h	Cat.h	Dog.h	Brain.h

CC		=	c++
GFLAGS	=	-Wall -Wextra -Werror -std=c++98

.PHONY	:	all clean fclean re

%.o		:	%.cpp $(FH)
			$(CC) $(GFLAGS) -c $< -o $(<:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(FO) $(FH)
			$(CC) $(GFLAGS) -o $(NAME) $(FO)

clean	:
			@rm -f $(FO)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all