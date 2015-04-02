//
// Snake.cpp for snakle in /home/moran-_d/rendu/cpp_nibbler
//
// Made by moran-_d
// Login   <moran-_d@epitech.net>
//
// Started on  Tue Mar 31 12:42:00 2015 moran-_d
// Last update Thu Apr  2 18:39:23 2015 terran_j
//

#include "Map.hh"
#include "Snake.hh"
#include "Item.hh"

Snake::Snake(std::map<int, Item*> *items, Map *map,
	     unsigned int x, unsigned int y,
	     int color, int id)
{
  this->alive = true;
  this->speed_modifier = 1;
  this->direction = 0;
  this->pos.push_front({x, y});
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
{}

int Snake::getNextCell(unsigned int *objective) const
{
  objective[0] = pos[0][0];
  objective[1] = pos[0][1];
  if (direction == 0) // ici t'as -42 coco, en cpp pas le droit a plus de if, else if, else
    --objective[0];
  else if (direction == 2)
    ++objective[0];
  else if (direction == 1)
    --objective[1];
  else if (direction == 3)
    ++objective[1];
  return (this->map->getCell(objective[0], objective[1]));
}

void Snake::harakiri()
{
  /*
  s << "Snake N" << this->id << " is dead." << std::endl
    << "He lived " << this->turn << " and got " << this->score << " points."
    << std::endl;
  */
  delete this;
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
      this->harakiri();
      return (-1);
    }
  this->reduce_tail();
  if (content < 0)
    {
      (*(this->items))[content]->use(this);
      if (this->alive == false)
	this->harakiri();
      return (-1);
    }
  if (this->moved == false)
    {
      this->map->setCell(this->pos.front()[0], this->pos.front()[1], 2);
      this->map->setCell(objective[0], objective[1], 1);
      this->pos.push_front({objective[0], objective[1]});
    }
  return (0);
}
