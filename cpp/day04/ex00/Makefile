NAME	=	animals

FC		=	main.cpp	Animal.cpp	Cat.cpp	Dog.cpp	WrongAnimal.cpp	WrongCat.cpp
FO		=	$(FC:%.cpp=%.o)
FH		=	Animal.h	Cat.h	Dog.h	WrongAnimal.h	WrongCat.h

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