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

void	GridInfos::drawLines(float valEnd, float valDraw, bool tf)
{
  glPointSize(this->sizeL);
  glBegin(GL_LINES);
  float i = -valEnd;
  while (i < valEnd)
    {
     // tf ? glColor3ub(72, 150, 233) : glColor3ub(255, 0, 0);
      glColor3ub(8, 89, 23);
      tf ? glVertex3f(-valDraw, i, 0.0f) : glVertex3f(i, -valDraw, 0.0f);
    //  tf ? glColor3ub(8, 89, 23) : glColor3ub(255, 0, 0);
      glColor3ub(0, 255, 100);
      tf ? glVertex3f(valDraw, i, 0.0f) : glVertex3f(i, valDraw, 0.0f);
      i += this->grid;
    }
  //tf ? glColor3ub(72, 150, 233) : glColor3ub(255, 0, 0);
      glColor3ub(8, 89, 23);
  tf ? glVertex3f(-valDraw, i, 0.0f) : glVertex3f(i, -valDraw, 0.0f);
  //tf ? glColor3ub(8, 89, 23) : glColor3ub(255, 0, 0);
      glColor3ub(0, 255, 100);
  tf ? glVertex3f(valDraw, i, 0.0f) : glVertex3f(i, valDraw, 0.0f);
}

void	GridInfos::draw()
{
  Cube	cube(this->mapWidth, this->mapHeight);
  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(3, 4, 15, 0, 0, 0, 0, 0, 1);
  // positions de la camera, postions point fixe par cam, positions vercteur vertical

  cube.drawCube();
  this->drawLines(this->mapHeight / 2, this->mapWidth / 2, true);
  this->drawLines(this->mapWidth / 2, this->mapHeight / 2, false);
  glEnd();
  glFlush();
  SDL_GL_SwapBuffers();
}