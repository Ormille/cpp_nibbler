##
## Makefile for nibbler in /home/terran_j/rendu/cpp_nibbler
##
## Made by Julie Terranova
## Login   <terran_j@epitech.net>
##
## Started on  Mon Mar 23 18:30:25 2015 Julie Terranova
## Last update Sun Apr  5 15:00:38 2015 terran_j
##

NAME_EXE =	nibbler
SRC_EXE =	src/main.cpp \
		src/DLLoader.cpp \
		src/nibbler.cpp \
		src/Snake.cpp \
		src/Map.cpp \
		src/BigFruit.cpp \
		src/SpeedFruit.cpp \
		src/SlowFruit.cpp \
		src/Fruit.cpp \
		src/ScoreFruit.cpp \
		src/Portal.cpp
OBJ_EXE =	$(SRC_EXE:.cpp=.o)

NAME_LIB1 =	lib_nibbler_sfml.so
SRC_LIB1 =	SFML/src/sfml.cpp
OBJ_LIB1 =	$(SRC_LIB1:.cpp=.o)

NAME_LIB2 =	lib_nibbler_opengl.so
SRC_LIB2 =	OpenGL/src/opengl.cpp \
		OpenGL/src/aff_draw.cpp \
		OpenGL/src/Cube.cpp
OBJ_LIB2 =	$(SRC_LIB2:.cpp=.o)

NAME_LIB3 =	lib_nibbler_ncurses.so
SRC_LIB3 =	nCurses/src/nCurses.cpp
OBJ_LIB3 =	$(SRC_LIB3:.cpp=.o)

CXX  =		g++
CXXFLAGS =	-Wall -Wextra -Werror -fPIC -I ./include -I ./SFML/include -I ./OpenGL/include -I ./nCurses/include -std=gnu++11

LDFLAGS =	-ldl -rdynamic -lGL -lGLU -lSDL -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lncurses

make:	all

$(NAME_EXE):$(OBJ_EXE)
	$(CXX) $(LDFLAGS) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS)

$(NAME_LIB1):$(OBJ_LIB1)
	$(CXX) -shared -o $(NAME_LIB1) $(OBJ_LIB1) -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

$(NAME_LIB2):$(OBJ_LIB2)
	$(CXX) -shared -o $(NAME_LIB2) $(OBJ_LIB2) -lGL -lGLU -lSDL

$(NAME_LIB3):$(OBJ_LIB3)
	$(CXX) -shared -o $(NAME_LIB3) $(OBJ_LIB3) -lncurses

all:    $(NAME_EXE) $(NAME_LIB1) $(NAME_LIB2) $(NAME_LIB3)

clean:
	rm -f $(OBJ_EXE) $(OBJ_LIB1) $(OBJ_LIB2) $(OBJ_LIB3)

fclean: clean
	rm -f $(NAME_EXE) $(NAME_LIB1) $(NAME_LIB2) $(NAME_LIB3)

re:     fclean all

.PHONY: all clean fclean re
