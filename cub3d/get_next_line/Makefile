NAME		= libget_next_line.a

CC			= cc

CFLAGS		= -Wall -Werror -Wextra

SRCS		= get_next_line.c		get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

HEADER		= get_next_line.h

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	@ar rcs $(NAME) $(OBJS)

$(OBJS) : %.o : %.c $(HEADER)
	@$(CC) -c $(CFLAGS) $< -o $@

clean :
	@rm -rf $(OBJS)

fclean :
	@rm -rf $(OBJS) $(NAME)

re : fclean all