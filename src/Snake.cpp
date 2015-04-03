//
// Snake.cpp for snakle in /home/moran-_d/rendu/cpp_nibbler
//
// Made by moran-_d
// Login   <moran-_d@epitech.net>
//
// Started on  Tue Mar 31 12:42:00 2015 moran-_d
// Last update Fri Apr  3 17:41:35 2015 moran-_d
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
  this->moved = false;
  this->speed_modifier = 1;
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
  this->left_key = 276;
  this->right_key = 275;
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

int Snake::getNextCell(unsigned int *objective, int direction) const
{
  objective[0] = this->pos[0][0];
  objective[1] = this->pos[0][1];
  if (direction == 0 || direction == 2)
    objective[0] += (!!direction) - (!direction);
  else if (direction == 1 || direction == 3)
    {
      --direction;
      objective[1] += (!!direction) - (!direction);
    }
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
  if (this->moved == true)
    return (-1);
  if (key == this->left_key)
    {
      direction = (direction + 1) % 4;
      this->moved = true;
      return (0);
    }
  else if (key == this->right_key)
    {
      if ((direction = (direction - 1)) < 0)
	direction = 3;
      this->moved = true;
      return (0);
    }
  return (-1);
}

void Snake::_enlarge(int part)
{
  std::array<unsigned int, 2> tmp;
  unsigned int obj[2];

  part = part;
  tmp[0] = (obj[0] = this->pos.back()[0]);
  tmp[1] = (obj[1] = this->pos.back()[1]);
  std::cout << "HERE ENTRY WITH x = " << tmp[0] << " y = " << tmp[1] << std::endl;
  this->map->setCell(obj[0], obj[1], 2);
  if (this->getNextCell(obj, (this->direction + 1) % 4) == 0)
    {
      this->pos.push_back(tmp);
      return;
    }
  tmp[0] = (obj[0] = this->pos.back()[0]);
  tmp[1] = (obj[1] = this->pos.back()[1]);
  if (this->getNextCell(obj, (this->direction + 2) % 4) == 0)
    {
      this->pos.push_back(tmp);
      return;
    }
  tmp[0] = (obj[0] = this->pos.back()[0]);
  tmp[1] = (obj[1] = this->pos.back()[1]);
  if (this->getNextCell(obj, (this->direction + 3) % 4) == 0)
    {
      this->pos.push_back(tmp);
      return;
    }
  this->alive = false;
}

void Snake::enlarge(int e)
{
  while (--e > 0)
    this->_enlarge(2);
  this->_enlarge(3);
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

  if ((content = this->getNextCell(objective, this->direction)) > 0)
    {
      std::cout << "FOUND OBSTACLE AHEAD OF SNAKE, VALUE = " << content << std::endl;
      return (this->harakiri());
    }
  this->reduce_tail();
  if (content < 0)
    {
      (*(this->items))[content]->use(this->map, this);
      if (this->alive == false)
	return (this->harakiri());
    }
  if (this->moved == false)
    {
      this->map->setCell(this->pos.front()[0], this->pos.front()[1], 2);
      this->map->setCell(objective[0], objective[1], 1);
      this->pos.push_front({objective[0], objective[1]});
    }
  this->moved = false;
  return (0);
}

void Snake::setLeft(int k)
{ this->left_key = k; }

void Snake::setRight(int k)
{ this->right_key = k; }

std::chrono::milliseconds Snake::getCounter() const
{ return (this->counter); }

void Snake::setCounter(const std::chrono::milliseconds &d)
{ this->counter = d; }

double Snake::getSpeedModifier() const
{ return (this->speed_modifier); }

void Snake::setMoved(bool b)
{ this->moved = b; }
