//
// nibbler.cpp for nibbler in /home/moran-_d/rendu/cpp_nibbler/src
//
// Made by moran-_d
// Login   <moran-_d@epitech.net>
//
// Started on  Mon Mar 30 17:32:11 2015 moran-_d
// Last update Fri Apr  3 00:09:58 2015 moran-_d
//

#include <stdio.h>
#include <chrono>
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
  if (key == 27)
    return false;
  return true;
}

void Nibbler::process_snake(std::chrono::system_clock::time_point &last)
{
  std::list<Snake*>::iterator it = this->snakes.begin();
  std::list<Snake*>::iterator next;
  std::chrono::system_clock::time_point cur;
  std::chrono::milliseconds counter;

  while (it != this->snakes.end())
    {
      ++(next = it);
      cur = std::chrono::system_clock::now();
      (*it)->setCounter( ( counter =
			   std::chrono::duration_cast<std::chrono::milliseconds>(cur - last)
			   + (*it)->getCounter()
			   ) );
      if (counter > SNAKE_WAIT * (*it)->getSpeedModifier())
	{
	  (*it)->setCounter(counter -
			    std::chrono::duration_cast<std::chrono::milliseconds>
			    (SNAKE_WAIT * (*it)->getSpeedModifier()));
	  (*it)->advance();
	  this->map->printMap();
	}
      it = next;
    }
  last = cur;
}

int Nibbler::process()
{
  std::chrono::system_clock::time_point last = std::chrono::system_clock::now();
  bool loop = true;
  int key = 0;

  if (this->init() < 0)
    return (-1);
  this->map->printMap();
  while (loop)
    {
      while (loop == true && (key = this->lib->getEvent()) >= 0)
	{
	  std::cout << "Key received : " << key << std::endl;
	  loop = this->applyEvent(key);
	}
      this->process_snake(last);
      this->lib->refreshImg(this->map->getMap());
    }
  lib->closeLib();
  return (0);
}
