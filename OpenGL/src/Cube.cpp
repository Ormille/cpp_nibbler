//
// Cube.cpp for  in /home/le-gue_n/Documents/tek2/cpp_nibbler/OpenGL/src
//
// Made by le-gue_n
// Login   <le-gue_n@epitech.net>
//
// Started on  Fri Apr  3 15:54:26 2015 le-gue_n
// Last update Fri Apr  3 15:54:27 2015 le-gue_n
//

#include <GL/gl.h>
#include "Cube.hh"

Cube::Cube(int mapW, int mapH)
{
  this->mapW = mapW;
  this->mapH = mapH;
  this->sizeW = 1.0 * (mapW / 2.0);
  this->sizeH = - (1.0 * (mapH / 2.0));
}

Cube::~Cube()
{

}

void	Cube::drawCube(int x, int y, std::tuple<int, int, int> rgb)
{
  float tmpW = this->sizeW - (y - 1);
  float tmpH = this->sizeH + (x - 1);

  glBegin(GL_QUADS);
  glColor3ub(std::get<0>(rgb), std::get<1>(rgb), std::get<2>(rgb));
 // front
  glVertex3f(tmpW - 1, tmpH + 1, 1.0f);
  glVertex3f(tmpW, tmpH + 1, 1.0f);
  glVertex3f(tmpW, tmpH + 1, 0.0f);
  glVertex3f(tmpW - 1, tmpH + 1, 0.0f);
  // back
  glVertex3d(tmpW - 1, tmpH, 1.0f);
  glVertex3d(tmpW - 1, tmpH, 0.0f);
  glVertex3d(tmpW, tmpH, 0.0f);
  glVertex3d(tmpW, tmpH, 1.0f);
  // top
  glVertex3f(tmpW, tmpH + 1, 1.0f);
  glVertex3f(tmpW, tmpH, 1.0f);
  glVertex3f(tmpW - 1, tmpH, 1.0f);
  glVertex3f(tmpW - 1, tmpH + 1, 1.0f);
  // bottom
  glVertex3f(tmpW, tmpH + 1, 0.0f);
  glVertex3f(tmpW, tmpH, 0.0f);
  glVertex3f(tmpW - 1, tmpH, 0.0f);
  glVertex3f(tmpW - 1, tmpH + 1, 0.0f);
  // left
  glVertex3d(tmpW, tmpH, 1.0f);
  glVertex3d(tmpW, tmpH, 0.0f);
  glVertex3d(tmpW, tmpH + 1, 0.0f);
  glVertex3d(tmpW, tmpH + 1, 1.0f);
  // right
  glVertex3d(tmpW - 1, tmpH, 1.0f);
  glVertex3d(tmpW - 1, tmpH, 0.0f);
  glVertex3d(tmpW - 1, tmpH + 1, 0.0f);
  glVertex3d(tmpW - 1, tmpH + 1, 1.0f);
  glEnd();
}

void	Cube::drawSnake(int x, int y, int nb)
{
  std::tuple<int, int, int> rgb;
  
  if (nb == 1) // tete
    rgb = std::make_tuple(133, 75, 25);//(19, 138, 41);
  else
    if (nb == 3) // queue
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
            this->drawOther(y, x, map[y][x]);
          else
            if (map[y][x] > 3)
              this->drawCube(y, x, rgb);
            else
              if (map[y][x] > 0)
                this->drawSnake(y, x, map[y][x]);
          x++;
        }
      y++;
    }
}
