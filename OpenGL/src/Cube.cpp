
#include <iostream>

#include <GL/gl.h>
#include "Cube.hh"

Cube::Cube(int mapW, int mapH)
{
  this->mapW = mapW;
  this->mapH = mapH;
  this->sizeW = 1.0 * (mapW / 2.0);
  this->sizeH = - (1.0 * (mapH / 2.0));
}
/*
Cube::Cube(const Cube &other)
{
  this->mapW = other.mapW;
  this->mapH = other.mapH;
  this->sizeH = other.sizeH;
}

Cube	&Cube::operator=(const Cube &other)
{
  if (this != &other)
    {
      this->infos = other.infos;
      this->sizeW = other.sizeW;
      this->sizeH = other.sizeH;
    }
  return (*this);
}*/

Cube::~Cube()
{

}

void	Cube::drawCube()
{
  /*this->sizeW -= 4;
  this->sizeH += 4;*/
  // place en 5 5

  glBegin(GL_QUADS);
// Top, front and left -face must be drawn counterclockwise and back, bottom and right in clockwise!

  glColor3f(0, 255, 0); // front

  glVertex3f(sizeW - 1, sizeH + 1, 1.0f);// -0.5f, 0.5f, 0.5f);
  glVertex3f(sizeW, sizeH + 1, 1.0f);// 0.5f, 0.5f, 0.5f);
  glVertex3f(sizeW, sizeH + 1, 0.0f);// 0.5f, 0.5f, -0.5f);
  glVertex3f(sizeW - 1, sizeH + 1, 0.0f);// -0.5f, 0.5f, -0.5f);

  //glColor3f(0, 0, 255); // back
  glVertex3d(sizeW - 1, sizeH, 1.0f);
  glVertex3d(sizeW - 1, sizeH, 0.0f);
  glVertex3d(sizeW, sizeH, 0.0f);
  glVertex3d(sizeW, sizeH, 1.0f);

  //glColor3f(0, 255, 0); // top
  glVertex3f(sizeW, sizeH + 1, 1.0f);
  glVertex3f(sizeW, sizeH, 1.0f);
  glVertex3f(sizeW - 1, sizeH, 1.0f);
  glVertex3f(sizeW - 1, sizeH + 1, 1.0f);

  //glColor3f(0, 255, 255); // bottom
  glVertex3f(sizeW, sizeH + 1, 0.0f);
  glVertex3f(sizeW, sizeH, 0.0f);
  glVertex3f(sizeW - 1, sizeH, 0.0f);
  glVertex3f(sizeW - 1, sizeH + 1, 0.0f);

  //glColor3ub(255,255, 0); // left
  glVertex3d(sizeW, sizeH, 1.0f);
  glVertex3d(sizeW, sizeH, 0.0f);
  glVertex3d(sizeW, sizeH + 1, 0.0f);
  glVertex3d(sizeW, sizeH + 1, 1.0f);

  //glColor3ub(255,0, 255); // right
  glVertex3d(sizeW - 1, sizeH, 1.0f);
  glVertex3d(sizeW - 1, sizeH, 0.0f);
  glVertex3d(sizeW - 1, sizeH + 1, 0.0f);
  glVertex3d(sizeW - 1, sizeH + 1, 1.0f);

  glEnd();
}

void	Cube::drawSquare()
{

}
