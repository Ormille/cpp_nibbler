##
## Makefile for nibbler in /home/terran_j/rendu/cpp_nibbler
##
## Made by Julie Terranova
## Login   <terran_j@epitech.net>
##
## Started on  Mon Mar 23 18:30:25 2015 Julie Terranova
## Last update Mon Mar 30 17:48:10 2015 moran-_d
##

NAME_EXE =	nibbler
SRC_EXE =	src/main.cpp \
		src/DLLoader.cpp \
		src/nibbler.cpp \
		src/Map.cpp
OBJ_EXE =	$(SRC_EXE:.cpp=.o)

NAME_LIB1 =	lib_nibbler_sfml.so
SRC_LIB1 =	SFML/src/sfml.cpp
OBJ_LIB1 =	$(SRC_LIB1:.cpp=.o)

NAME_LIB2 =	lib_nibbler_opengl.so
SRC_LIB2 =	OpenGL/src/opengl.cpp
OBJ_LIB2 =	$(SRC_LIB2:.cpp=.o)

NAME_LIB3 =	lib_nibbler_minilibx.so
SRC_LIB3 =	MinilibX/src/minilibx.cpp
OBJ_LIB3 =	$(SRC_LIB3:.cpp=.o)

CXX  =		g++
CXXFLAGS =	-Wall -Wextra -Werror -fPIC -I ./include -I ./SFML/include -I ./OpenGL/include -I ./MinilibX/include -g

LDFLAGS =	-ldl -rdynamic

make:	all

$(NAME_EXE):$(OBJ_EXE)
	$(CXX) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS)

$(NAME_LIB1):$(OBJ_LIB1)
	$(CXX) -shared -o $(NAME_LIB1) $(OBJ_LIB1)

$(NAME_LIB2):$(OBJ_LIB2)
	$(CXX) -shared -o $(NAME_LIB2) $(OBJ_LIB2)

$(NAME_LIB3):$(OBJ_LIB3)
	$(CXX) -shared -o $(NAME_LIB3) $(OBJ_LIB3)

all:    $(NAME_EXE) $(NAME_LIB1) $(NAME_LIB2) $(NAME_LIB3)

clean:
	rm -f $(OBJ_EXE) $(OBJ_LIB1) $(OBJ_LIB2) $(OBJ_LIB3)

fclean: clean
	rm -f $(NAME_EXE) $(NAME_LIB1) $(NAME_LIB2) $(NAME_LIB3)

re:     fclean all

.PHONY: all clean fclean re
