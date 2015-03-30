//
// Map.cpp for map in /home/moran-_d/rendu/cpp_nibbler/src
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Mon Mar 30 15:46:57 2015 moran-_d
// Last update Mon Mar 30 17:36:27 2015 moran-_d
//

#include "Map.hh"

Map::Map(unsigned int x, unsigned int y)
  : x(x), y(y)
{
  unsigned int i;

  this->map = new int*[x]();
  for (i = 1; i < y; i++)
    this->map[i] = new int[y]();
}

Map::~Map()
{
  unsigned int i;

  for (i = 0; i < this->y; i++)
    delete this->map[i];
  delete this->map;
}

int **Map::getMap() const
{
  return this->map;
}
