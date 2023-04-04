NAME			=	hewaw

CC				=	c++
CFLAGS			=	-std=c++98 -Wall -Wextra -Werror -MMD
IFLAGS			=	-I./$(DIR_INC)

DIR_INC			=	./inc
DIR_SRC			=	./src
DIR_OBJ			=	./obj

SRC				=	Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp main.cpp
OBJ				=	$(SRC:%.cpp=$(DIR_OBJ)/%.o)
DEP				=	$(SRC:%.cpp=$(DIR_OBJ)/%.d)

RED				=	$'\e[0;31m
GREEN			=	$'\e[32m
YELLOW			=	$'\e[33m
BOLD			=	$'\e[1m
UNDER			=	$'\e[4m
END				=	$'\e[0m

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.cpp Makefile
					mkdir -p $(DIR_OBJ)
					echo "Compiling - ${YELLOW}${BOLD}${UNDER}$<${END}..."
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
					echo "${GREEN}Done !${END}"

$(NAME):			$(OBJ)
					echo "Compiling - ${YELLOW}${BOLD}${UNDER}./$(NAME)${END}..."
					$(CC) $(OBJ) -o $(NAME)
					echo "${GREEN}Done !${END}"
					echo "${GREEN}${BOLD}${UNDER}Task completed successfully.${END}"

all:				$(NAME)

clean:
					echo "Deleting - ${RED}${BOLD}${UNDER}$(DIR_OBJ)/${END}..."
					rm -rf $(DIR_OBJ)
					echo "${GREEN}Done !${END}"
					echo "${GREEN}${BOLD}${UNDER}Task completed successfully.${END}"

fclean:
					echo "Deleting - ${RED}${BOLD}${UNDER}$(DIR_OBJ)/${END}..."
					rm -rf $(DIR_OBJ)
					echo "${GREEN}Done !${END}"
					echo "Deleting - ${RED}${BOLD}${UNDER}./$(NAME)${END}..."
					rm -rf $(NAME)
					echo "${GREEN}Done !${END}"
					echo "${GREEN}${BOLD}${UNDER}Task completed successfully.${END}"

re:
					echo "Deleting - ${RED}${BOLD}${UNDER}$(DIR_OBJ)/${END}..."
					rm -rf $(DIR_OBJ)
					echo "${GREEN}Done !${END}"
					echo "Deleting - ${RED}${BOLD}${UNDER}./$(NAME)${END}..."
					rm -rf $(NAME)
					echo "${GREEN}Done !${END}"
					make --no-print-directory all

git:
					git add .
					git commit -m "$(NAME)"
					git push

-include $(DEP)

.PHONY:				all clean fclean re git
.SILENT:
