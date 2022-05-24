NAME	= megaphone

SRC		= megaphone.cpp

CPP		= c++
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:	$(NAME)

${NAME}:
	${CPP} ${CFLAGS} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re