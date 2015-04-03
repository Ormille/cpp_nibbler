
//#include <iostream>

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

void	Cube::drawSquare()
{

}

void	Cube::drawCube(int x, int y, std::tuple<int, int, int> rgb)
{
  float tmpW = this->sizeW - (y - 1);
  float tmpH = this->sizeH + (x - 1);
  // 4 4 place en 5 5

  glBegin(GL_QUADS);
// Top, front and left -face must be drawn counterclockwise and back, bottom and right in clockwise!

 // glColor3f(std::get<0>(rgb), std::get<1>(rgb), std::get<2>(rgb)); // front
 glColor3ub(std::get<0>(rgb), std::get<1>(rgb), std::get<2>(rgb)); // front
  
  glVertex3f(tmpW - 1, tmpH + 1, 1.0f);// -0.5f, 0.5f, 0.5f);
  glVertex3f(tmpW, tmpH + 1, 1.0f);// 0.5f, 0.5f, 0.5f);
  glVertex3f(tmpW, tmpH + 1, 0.0f);// 0.5f, 0.5f, -0.5f);
  glVertex3f(tmpW - 1, tmpH + 1, 0.0f);// -0.5f, 0.5f, -0.5f);

  //glColor3f(0, 0, 255); // back
  glVertex3d(tmpW - 1, tmpH, 1.0f);
  glVertex3d(tmpW - 1, tmpH, 0.0f);
  glVertex3d(tmpW, tmpH, 0.0f);
  glVertex3d(tmpW, tmpH, 1.0f);

  //glColor3f(0, 255, 0); // top
  glVertex3f(tmpW, tmpH + 1, 1.0f);
  glVertex3f(tmpW, tmpH, 1.0f);
  glVertex3f(tmpW - 1, tmpH, 1.0f);
  glVertex3f(tmpW - 1, tmpH + 1, 1.0f);

  //glColor3f(0, 255, 255); // bottom
  glVertex3f(tmpW, tmpH + 1, 0.0f);
  glVertex3f(tmpW, tmpH, 0.0f);
  glVertex3f(tmpW - 1, tmpH, 0.0f);
  glVertex3f(tmpW - 1, tmpH + 1, 0.0f);

  //glColor3ub(255,255, 0); // left
  glVertex3d(tmpW, tmpH, 1.0f);
  glVertex3d(tmpW, tmpH, 0.0f);
  glVertex3d(tmpW, tmpH + 1, 0.0f);
  glVertex3d(tmpW, tmpH + 1, 1.0f);

  //glColor3ub(255,0, 255); // right
  glVertex3d(tmpW - 1, tmpH, 1.0f);
  glVertex3d(tmpW - 1, tmpH, 0.0f);
  glVertex3d(tmpW - 1, tmpH + 1, 0.0f);
  glVertex3d(tmpW - 1, tmpH + 1, 1.0f);

  glEnd();
}

void	Cube::drawSnake(int x, int y, int nb)
{
  std::tuple<int, int, int> rgb;
  //nb = nb; // tmp
  if (nb == 1)
    rgb = std::make_tuple(133, 75, 25);//(19, 138, 41);
  else if (nb == 3)
    rgb = std::make_tuple(184, 159, 103);//(3, 59, 13);
  else
    rgb = std::make_tuple(82, 44, 11);//(13, 97, 28);
  this->drawCube(x, y, rgb);
}

void	Cube::drawOther(int x, int y, int nb)
{
  std::tuple<int, int, int> rgb;
  if (nb == -1)
    rgb = std::make_tuple(223, 240, 115);
  else
    rgb = std::make_tuple(50, 48, 82);
  this->drawCube(x, y, rgb);
}

void	Cube::drawMapItems(int **map)
{
  std::tuple<int, int, int> rgb;
  int	y = 0;

  rgb = std::make_tuple(41, 41, 41);
  while (y < this->mapW + 2)
    {
      int	x = 0;
      while (x < this->mapH + 2)
	{
	  if (map[y][x] < 0)
	    this->drawOther(x, y, map[y][x]);
	  else if (map[y][x] > 3)
	    this->drawCube(x, y, rgb);
	  else if (map[y][x] > 0)
	    this->drawSnake(x, y, map[y][x]);
	  x++;
	}
      y++;
    }
}