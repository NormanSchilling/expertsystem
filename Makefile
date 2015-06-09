export	CC	=	g++

NAME		=	expertsystem

CFLAGS		= -Wall -Wextra -Werror -O3

INC			+=	-I includes

INC_DIR		=	includes/

INC_FILES	=	expertsystem.hpp \
				fact.hpp \
				operation.hpp \
				operator.hpp \
				rule.hpp \
				part.hpp

INC_SRC		=	$(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR		=	srcs/

FILES		=	main.cpp \
				expertsystem.cpp \
				fact.cpp \
				operation.cpp \
				operator.cpp \
				rule.cpp \
				part.cpp

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

OBJ			=	$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(INC_SRC)

%.o:			%.cpp $(INC_SRC)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
re:				fclean all

.PHONY:			all clean fclean re