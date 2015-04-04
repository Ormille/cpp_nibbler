//
// SpeedFruit.hh for bigfrt in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 17:51:01 2015 moran-_d
// Last update Sat Apr  4 20:59:30 2015 moran-_d
//

#include "SpeedFruit.hh"

SpeedFruit::SpeedFruit()
{
  this->id = -4;
}

SpeedFruit::~SpeedFruit()
{}

void SpeedFruit::turn(Map *map)
{
  this->span += 1;
  if (this->exist == false)
    if (random() % 10000 > 9987)
      this->pop(map);
}

void SpeedFruit::use(Map *map, Snake *snake, unsigned int *obj)
{
  obj = obj;
  snake->setSpeedModifier(snake->getSpeedModifier() * 0.75);
  this->exist = false;
  map->setCell(this->pos[0], this->pos[1], 0);
}
