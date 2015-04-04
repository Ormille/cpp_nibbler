//
// SlowFruit.hh for bigfrt in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 17:51:01 2015 moran-_d
// Last update Sat Apr  4 17:15:25 2015 moran-_d
//

#include "SlowFruit.hh"

SlowFruit::SlowFruit()
{
  this->id = -5;
}

SlowFruit::~SlowFruit()
{}

void SlowFruit::turn(Map *map)
{
  this->span += 1;
  if (this->exist == false)
    if (random() % 10000 > 9987)
      this->pop(map);
}

void SlowFruit::use(Map *map, Snake *snake, unsigned int *obj)
{
  obj = obj;
  snake->setSpeedModifier(snake->getSpeedModifier() * 0.8);
  this->exist = false;
  map->setCell(this->pos[0], this->pos[1], 0);
}
