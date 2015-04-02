//
// Map.cpp for map in /home/moran-_d/rendu/cpp_nibbler/src
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Mon Mar 30 15:46:57 2015 moran-_d
// Last update Thu Apr  2 16:35:56 2015 moran-_d
//

#include <iostream>
#include "Map.hh"

Map::Map(unsigned int x, unsigned int y)
  : x(x + 2), y(y + 2)
{
  unsigned int i;
  unsigned int t;

  this->map = new int*[this->x];
  for (i = 0; i < this->x; i++)
    {
      this->map[i] = new int[this->y]();
      if (i == 0 || i == this->x - 1)
	for (t = 0; t < this->y; t++)
	  this->map[i][t] = 2147483647;
    }
  for (i = 0; i < this->x; i++)
    {
      this->map[i][0] = 2147483647;
      this->map[i][this->y - 1] = 2147483647;
    }
}

Map::~Map()
{
  unsigned int i;

  for (i = 0; i < this->y; i++)
    delete[] this->map[i];
  delete[] this->map;
}

void Map::printMap()
{
  unsigned int i;
  unsigned int t;

  for (i = 0; i < this->x; i++)
    {
      for (t = 0; t < this->y; t++)
	std::cout << this->map[i][t] << " ";
      std::cout << std::endl;
    }
}

int Map::setCell(unsigned int x, unsigned int y, int val)
{
  int tmp;

  tmp = this->map[x][y];
  this->map[x][y] = val;
  return (tmp);
}

int Map::getCell(unsigned int x, unsigned int y) const
{
  return this->map[x][y];
}

int **Map::getMap() const
{
  return this->map;
}

int Map::getX() const
{
  return this->x;
}

int Map::getY() const
{
  return this->y;
}
