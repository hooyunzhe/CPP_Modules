NAME	= form

SRC		= main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

CPP		= c++ -std=c++98
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:	${NAME}

${NAME}:
	${CPP} ${CFLAGS} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re