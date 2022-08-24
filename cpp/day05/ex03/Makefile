NAME	=	bureaucrat

FC		=	main.cpp					Bureaucrat.cpp				AForm.cpp\
			PresidentialPardonForm.cpp	RobotomyRequestForm.cpp		ShrubberyCreationForm.cpp\
			Intern.cpp
FO		=	$(FC:%.cpp=%.o)
FH		=	Bureaucrat.h	AForm.h		PresidentialPardonForm.h	RobotomyRequestForm.h\
			ShrubberyCreationForm.h		Intern.h

TRASH	=	*_shrubbery

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
			@rm -f $(NAME) $(TRASH)

re		:	fclean all