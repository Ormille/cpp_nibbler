//
// Snake.cpp for snakle in /home/moran-_d/rendu/cpp_nibbler
//
// Made by moran-_d
// Login   <moran-_d@epitech.net>
//
// Started on  Tue Mar 31 12:42:00 2015 moran-_d
// Last update Fri Apr  3 08:30:09 2015 le-gue_n
//

#include <iostream>
#include "Map.hh"
#include "Snake.hh"
#include "Item.hh"

Snake::Snake(std::map<int, Item*> *items, Map *map,
	     unsigned int x, unsigned int y,
	     int color, int id)
{
  this->alive = true;
  this->counter = std::chrono::milliseconds::zero();
  this->speed_modifier = 0.2;
  this->direction = 0;
  this->pos.push_front({x + 1, y});
  this->pos.push_front({x, y});
  this->pos.push_front({x - 1, y});
  this->pos.push_front({x - 2, y});
  this->items = items;
  this->map = map;
  this->map->setCell(x - 2, y, 1);
  this->map->setCell(x - 1, y, 2);
  this->map->setCell(x, y, 2);
  this->map->setCell(x + 1, y, 3);
  this->left_key = (this->right_key = -1);
  this->turn = 0;
  this->score = 0;
  this->color = color;
  this->id = id;
}

Snake::~Snake()
{
  for (auto it = this->pos.begin();
       it != this->pos.end(); ++it)
    this->map->setCell((*it)[0], (*it)[1], 0);
}

int Snake::getNextCell(unsigned int *objective) const
{
  objective[0] = this->pos[0][0];
  objective[1] = this->pos[0][1];
  if (direction == 0) // ici t'as -42 coco, en cpp pas le droit a plus de if, else if, else
    --objective[0];
  else if (direction == 2)
    ++objective[0];
  else if (direction == 1)
    --objective[1];
  else if (direction == 3)
    ++objective[1];
  std::cout << "objective : " << objective[0] << ":" << objective[1] << std::endl;
  std::cout << "pos       : " << this->pos[0][0] << ":" << this->pos[0][1] << std::endl;
  return (this->map->getCell(objective[0], objective[1]));
}

int Snake::harakiri()
{
  /*
  s << "Snake N" << this->id << " is dead." << std::endl
    << "He lived " << this->turn << " and got " << this->score << " points."
    << std::endl;
  */
  delete this;
  return (-1);
}

int Snake::tryDirKey(int key)
{
  if (key == this->left_key)
    {
      return (0);
    }
  else if (key == this->right_key)
    {
      return (0);
    }
  return (-1);
}

void Snake::reduce_tail()
{
  this->map->setCell(this->pos.back()[0], this->pos.back()[1], 0);
  this->pos.pop_back();
  this->map->setCell(this->pos.back()[0], this->pos.back()[1], 3);
}

int Snake::advance()
{
  unsigned int objective[2];
  int content;

  this->moved = false;
  if ((content = this->getNextCell(objective)) > 0)
    {
      std::cout << "FOUND OBSTACLE AHEAD OF SNAKE, VALUE = " << content << std::endl;
      return (this->harakiri());
    }
  this->reduce_tail();
  if (content < 0)
    {
      (*(this->items))[content]->use(this);
      if (this->alive == false)
	return (this->harakiri());
    }
  if (this->moved == false)
    {
      this->map->setCell(this->pos.front()[0], this->pos.front()[1], 2);
      this->map->setCell(objective[0], objective[1], 1);
      this->pos.push_front({objective[0], objective[1]});
    }
  return (0);
}

std::chrono::milliseconds Snake::getCounter() const
{ return (this->counter); }

void Snake::setCounter(const std::chrono::milliseconds &d)
{ this->counter = d; }

double Snake::getSpeedModifier() const
{ return (this->speed_modifier); }
