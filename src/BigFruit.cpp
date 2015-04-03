//
// BigFruit.hh for bigfrt in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 17:51:01 2015 moran-_d
// Last update Fri Apr  3 18:15:29 2015 moran-_d
//

#include "BigFruit.hh"

BigFruit::BigFruit()
{
  this->id = -2;
}

BigFruit::~BigFruit()
{}

void BigFruit::turn(Map *map)
{
  this->span += 1;
  if (this->exist == false)
    if (random() % 10000 > 9975)
      this->pop(map);
}

void BigFruit::use(Map *map, Snake *snake)
{
  snake->enlarge((random() % 5) + 1);
  this->exist = false;
  map->setCell(this->pos[0], this->pos[1], 0);
}
