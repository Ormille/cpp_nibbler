//
// premier_test.cpp for  in /home/le-gue_n/Documents/tek2/TP/c++/opengl
//
// Made by le-gue_n
// Login   <le-gue_n@epitech.net>
//
// Started on  Fri Mar 27 11:05:47 2015 le-gue_n
// Last update Fri Mar 27 20:30:26 2015 le-gue_n
//

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
//#include <cstdlib>
#include <iostream>

#include "Grid.hh"
#include "Cube.hh"

GridInfos::GridInfos(int mapW, int mapH)
{
  this->mapWidth = mapW;
  this->mapHeight = mapH;
  this->sizeL = 3.0;
  this->grid = 1.0;
}
/*
GridInfos::GridInfos(const GridInfos &other)
{
  this->mapWidth = other.mapWidth;
  this->mapHeight = other.mapHeight;
  this->sizeL = other.sizeL;
  this->grid = other.grid;
}

GridInfos	&GridInfos::operator=(const GridInfos &other)
{
  if (this != &other)
    {
      this->mapWidth = other.mapWidth;
      this->mapHeight = other.mapHeight;
      this->sizeL = other.sizeL;
      this->grid = other.grid;
    }
  return (*this);
}*/

GridInfos::~GridInfos()
{

}

int	GridInfos::getMapWidth() const
{
  return (this->mapWidth);
}

int	GridInfos::getMapHeigth() const
{
  return (this->mapHeight);
}

void	GridInfos::draw()
{
  Cube	cube(this->mapWidth, this->mapHeight);
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(3, 4, 11, 0, 0, 0, 0, 0, 1);
  // positions de la camera, postions point fixe par cam, positions vercteur vertical

  cube.drawCube();

  glPointSize(this->sizeL);
  glBegin(GL_LINES);
  float i = -this->mapHeight / 2;
  while (i < this->mapHeight / 2)
    {

      glColor3ub(72, 150, 233);
      glVertex3f(-(this->mapWidth / 2), i, 0.0f);
      glColor3ub(255, 255, 0);
      glVertex3f(this->mapWidth / 2, i, 0.0f);

      /* glColor3ub(8, 89, 23);
        glVertex3f(i, -size, 0.0f);
        glColor3ub(0, 255, 255);
        glVertex3f(i, size, 0.0f);*/

      i += this->grid;
    }
  glVertex3f(-(this->mapWidth / 2), i, 0.0f);
  glVertex3f(this->mapWidth / 2, i, 0.0f);
  i = -this->mapWidth / 2;
  while (i < this->mapWidth / 2)
    {

      /* glColor3ub(72, 150, 233);
        glVertex3f(-size, i, 0.0f);
        glColor3ub(255, 255, 0);
        glVertex3f(size, i, 0.0f);*/

      glColor3ub(8, 89, 23);
      glVertex3f(i, -(this->mapHeight / 2), 0.0f);
      glColor3ub(0, 255, 255);
      glVertex3f(i, this->mapHeight / 2, 0.0f);

      i += this->grid;
    }

  glVertex3f(i, -(this->mapHeight / 2), 0.0f);
  glVertex3f(i, this->mapHeight / 2, 0.0f);
  glEnd();
  glFlush();
  SDL_GL_SwapBuffers();
}
/*
int main() // aff
{
  SDL_Event event;
  double x =  1.0f * (5 / 2);
// double y = 1;

  GridInfos infos(11, 11);

  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);
  SDL_WM_SetCaption("Nibbler", NULL);
  SDL_SetVideoMode(winHeight, winWidth, 32, SDL_OPENGL);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (double)winHeight / winWidth, 1, 1000);
  glEnable(GL_DEPTH_TEST);

  infos.draw(&infos);

  for (;;)
    {
      SDL_WaitEvent(&event);

      switch (event.type)
        {
        case SDL_QUIT:
          exit(0);
          break;
        }

      infos.draw(&infos);

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

    }

  return 0;
}
*/