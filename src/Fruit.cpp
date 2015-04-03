//
// Fruit.cpp for fruit in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 14:16:59 2015 moran-_d
// Last update Fri Apr  3 17:59:39 2015 moran-_d
//

#include "Fruit.hh"

Fruit::Fruit()
  : Item(-1, false, 0)
{}

Fruit::~Fruit()
{}

int Fruit::pop(Map *map)
{
  int obj[2];

  if (this->exist == true)
    return (-1);
  if (map->fillRandomEmptyCellWith(this->id, obj) < 0)
    return (-1);
  this->exist = true;
  this->span = 0;
  this->pos[0] = obj[0];
  this->pos[1] = obj[1];
  return (0);
}

void Fruit::turn(Map *map)
{
  map = map;
  this->span += 1;
}

void Fruit::use(Map *map, Snake *snake)
{
  snake->enlarge(1);
  this->exist = false;
  map->setCell(this->pos[0], this->pos[1], 0);
  this->pop(map);
}
