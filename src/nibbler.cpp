//
// nibbler.cpp for nibbler in /home/moran-_d/rendu/cpp_nibbler/src
//
// Made by moran-_d
// Login   <moran-_d@epitech.net>
//
// Started on  Mon Mar 30 17:32:11 2015 moran-_d
// Last update Fri Apr  3 11:35:01 2015 moran-_d
//

#include <cstdlib>
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
  this->paused = false;
}

Nibbler::~Nibbler()
{}

int Nibbler::popSnake(unsigned int x, unsigned int y, int color)
{
  Snake *snew;

  snew = new Snake(this->items, this->map,
		   x, y,
		   color, ++this->snakeCount);
  this->snakes.push_front(snew);
  return (0);
}

void Nibbler::popNewSnake()
{
  int tries = 0;
  bool ok = false;
  int obj[2];

  while (ok == false && tries < 1000)
    {
      obj[0] = (random() % (this->map->getX() - 3)) + 1;
      obj[1] = (random() % (this->map->getY() - 3)) + 1;
      if (this->map->getCell(obj[0] + 1, obj[1]) == 0 &&
	  this->map->getCell(obj[0], obj[1]) == 0 &&
	  this->map->getCell(obj[0] - 1, obj[1]) == 0 &&
	  this->map->getCell(obj[0] - 2, obj[1]) == 0)
	{
	  ok = true;
	  this->paused = true;
	  this->popSnake(obj[0], obj[1], 0x00FF00);
	  tries = -1;
	  while (tries < 0)
	    tries = this->lib->getEvent();
	  this->snakes.front()->setLeft(tries);
	  tries = -1;
	  while (tries < 0)
	    tries = this->lib->getEvent();
	  this->snakes.front()->setRight(tries);
	  this->paused = false;
	}
      ++tries;
    }
}

void Nibbler::reset_snake() const
{
  for (std::list<Snake*>::const_iterator it = this->snakes.begin(); it != this->snakes.end(); ++it)
    it = it;
}

bool Nibbler::applyEvent(int key)
{
  if (key == 27)
    return false;
  else if (key == 8)
    this->popNewSnake();
  else if (key == 32)
    this->paused = !this->paused;
  for (std::list<Snake*>::iterator it = this->snakes.begin(); it != this->snakes.end(); ++it)
    (*it)->tryDirKey(key);
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
	  (*it)->setMoved(false);
	  (*it)->setCounter(counter -
			    std::chrono::duration_cast<std::chrono::milliseconds>
			    (SNAKE_WAIT * (*it)->getSpeedModifier()));
	  if (this->paused == false && (*it)->advance() == -1)
	    this->snakes.erase(it);
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

  if (this->popSnake(this->map->getX() / 2, this->map->getY() / 2, 0xFF00FF) < 0)
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
