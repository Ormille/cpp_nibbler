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

void    OpenGL::initLib(unsigned int x, unsigned int y)
{
  SDL_Surface	*screen;

  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);
  SDL_WM_SetCaption("Nibbler", NULL);
  screen = SDL_SetVideoMode(winHeight, winWidth, 32, SDL_OPENGL);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (double)winHeight / winWidth, 1, 1000);
  glEnable(GL_DEPTH_TEST);

  this->_mapX = x;
  this->_mapY = y;
  this->_screen = screen;
  this->_grid = new GridInfos(x, y);
}

int    OpenGL::getEvent()
{
  
  return (0);
}

void    OpenGL::refreshImg(int **map)
{
  map = map; // a virer
  this->_grid->draw();
}

void	OpenGL::testRefImg()
{
  this->_grid->draw();
}

void    OpenGL::affText(const std::string &toAff)
{
  std::cout << toAff << std::endl; // a virer
}

void	OpenGL::closeLib()
{

}
/*
int	main()
{*/
 /* int	z[2];
  int	*fake_map = new int[10];*/
 /* OpenGL *test = new OpenGL();
  SDL_Event event;
  bool	quit = false;

  test->initLib(10, 15);
  while (!quit)
    {
      SDL_WaitEvent(&event);

      switch (event.type)
        {
        case SDL_QUIT:
          quit = true;
          break;
        }

      //test->refreshImg(fake_map);
      test->testRefImg();*/
/*
      switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
          x += 0.5;
          break;
        case SDLK_RIGHT:
          x -= 0.5;
          break;
        default
            :
          break;
        }
*/
 /*   }
  return (0); 
}
*/
extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "OpenGL loaded." << std::endl;
  return (new OpenGL());
}
