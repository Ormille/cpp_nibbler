//
// SpeedFruit.hh for bigfrt in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 17:51:01 2015 moran-_d
// Last update Sat Apr  4 22:17:58 2015 moran-_d
//

#include "ScoreFruit.hh"

ScoreFruit::ScoreFruit()
{
  this->id = -6;
}

ScoreFruit::~ScoreFruit()
{}

void ScoreFruit::turn(Map *map)
{
  this->span += 1;
  if (this->exist == false)
    {
      if (random() % 10000 > 9925)
	this->pop(map);
    }
  else
    {
      if (random() % 10000 > 9990)
	{
	  this->exist = false;
	  map->setCell(this->pos[0], this->pos[1], 0);
	}
    }
}

void ScoreFruit::use(Map *map, Snake *snake, unsigned int *obj)
{
  obj = obj;
  snake->setScore(snake->getScore() + 50);
  this->exist = false;
  map->setCell(this->pos[0], this->pos[1], 0);
}
