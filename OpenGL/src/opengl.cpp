//
// opengl.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:04:19 2015 Julie Terranova
// Last update Wed Apr  1 18:24:25 2015 terran_j
//

#include <iostream>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <SDL/SDL_ttf.h>
//#include <GL/glut.h>

#include "opengl.hh"

OpenGL::OpenGL()
{
  this->_mapX = 0;
  this->_mapY = 0;
  this->_screen = NULL;
  this->_grid = new GridInfos(0, 0);
}

OpenGL::~OpenGL()
{}

int    OpenGL::initLib(unsigned int x, unsigned int y)
{
  if (x > mapMax || y > mapMax || x < mapMin || y < mapMin)
    {
      std::cout << "Map minimum size : " << mapMin << " * " << mapMin << "; maximum size : " << mapMax << " * " << mapMax << std::endl;
      return (-1);
    }
  SDL_Surface	*screen;

  if (SDL_Init(SDL_INIT_VIDEO)  < 0/*|| TTF_Init() < 0*/)
    {
      std::cout << "Init did not worked." << std::endl;
      return (-1);
    }
  //atexit(SDL_Quit);
  SDL_WM_SetCaption("Nibbler", NULL);
  if ((screen = SDL_SetVideoMode(winHeight, winWidth, 32, SDL_OPENGL)) == NULL)
    {
      std::cout << "Could not set video mode." << std::endl;
      return (-1);
    }
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (double)winHeight / winWidth, 1, 1000);
  glEnable(GL_DEPTH_TEST);
  this->_mapX = x;
  this->_mapY = y;
  this->_screen = screen;
  this->_grid = new GridInfos(x, y);
  return (0);
}

int    OpenGL::getEvent()
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	return (27);
      else if (event.type == SDL_KEYDOWN)
	return (event.key.keysym.sym);
    }
  return (-1);
}

void    OpenGL::refreshImg(int **map)
{
  this->_grid->draw(map);
}

void    OpenGL::affText(const std::string &toAff)
{
  std::cout << toAff << std::endl; // a virer
}

void	OpenGL::closeLib()
{
  /*std::string str("You lose!");
  
  glColor3ub(255, 255, 255);
  glRasterPos2f(0, 0);
  int i;
  int len = str.length();
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]); // ->undefined symbol GLUT_BITMAP_9_BY_15
  }*/
 
 // TTF_Quit();
  
  SDL_Quit();
}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "OpenGL loaded." << std::endl;
  return (new OpenGL());
}
