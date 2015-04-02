//
// nibbler.cpp for nibbler in /home/moran-_d/rendu/cpp_nibbler/src
//
// Made by moran-_d
// Login   <moran-_d@epitech.net>
//
// Started on  Mon Mar 30 17:32:11 2015 moran-_d
// Last update Thu Apr  2 17:25:45 2015 terran_j
//

#include <iostream>
#include "nibbler.hh"

Nibbler::Nibbler(unsigned int x, unsigned int y, IObjGraph *lib)
{
  this->snakeCount = 0;
  this->map = new Map(x, y);
  this->items = new std::map<int, Item*>();
  this->lib = lib;
}

Nibbler::~Nibbler()
{}

int Nibbler::init()
{
  Snake *snew;

  snew = new Snake(this->items, this->map,
		   this->map->getX() / 2, this->map->getY() / 2,
		   0xFF0000, ++this->snakeCount);
  this->snakes.push_front(snew);
  return (0);
}

bool Nibbler::applyEvent(int key)
{
  if (key == 36) // touche echap
    return false;
  return (true);
}

int Nibbler::process()
{
  bool loop = true;
  int key = 0;

  if (this->init() < 0)
    return (-1);
  this->map->printMap();
  while (loop)
    {
      while (loop == true && (key = this->lib->getEvent()) > 0)
	{
	  std::cout << "Key received : " << key << std::endl;
	  loop = this->applyEvent(key);
	}
      /*
      for (std::list<Snake*>::iterator it = this->snakes.begin(); it != this->snakes.end(); ++it)
	(*it)->advance();
      */
      this->lib->refreshImg(this->map->getMap());
    }
  lib->closeLib();
  return (0);
}
