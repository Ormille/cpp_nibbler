//
// Portal.cpp for portal in /home/moran-_d/rendu/cpp_nibbler/src
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Sat Apr  4 16:49:51 2015 moran-_d
// Last update Sat Apr  4 19:49:01 2015 moran-_d
//

#include <iostream>
#include "Portal.hh"

Portal::Portal()
  : Item(-100, false, 0)
{}

Portal::~Portal()
{}

int Portal::pop(Map *map)
{
  if (this->exist == true)
    return (-1);
  if (map->fillRandomEmptyCellWith(this->id, this->pos1) < 0)
    return (-1);
  if (map->fillRandomEmptyCellWith(this->id, this->pos2) < 0)
    return (-1);
  this->exist = true;
  this->span = 0;
  return (0);
}

void Portal::turn(Map *map)
{
  map = map;
  this->span += 1;
}

void Portal::_use(Map *map, Snake *snake, unsigned int *tmp) const
{
  unsigned int obj[2] = {tmp[0], tmp[1]};
  int content;

  if ((content = snake->_getNextCell(obj, snake->getDirection())) > 0)
    {
      snake->setAlive(false);
      return;
    }
  if (content < 0)
    {
      (*(snake->getItems()))[content]->use(map, snake, obj);
      if (snake->getAlive() == false)
	return;
    }
  if (snake->getMoved() == false)
    {
      snake->setMoved(true);
      map->setCell(obj[0], obj[1], 1);
      snake->pushPosFront(obj[0], obj[1]);
    }
}

void Portal::use(Map *map, Snake *snake, unsigned int *obj)
{
  if (obj[0] == this->pos1[0] && obj[1] == this->pos1[1])
    this->_use(map, snake, this->pos2);
  else
    this->_use(map, snake, this->pos1);
}

