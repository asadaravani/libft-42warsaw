SRCS		= 	$(wildcard *.c)
OBJS		= 	$(SRCS:.c=.o)
CC			=	cc
RM			=	rm -f
FLAGS		=	-Wall -Wextra -Werror

NAME		=	libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
