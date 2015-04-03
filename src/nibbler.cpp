//
// nibbler.cpp for nibbler in /home/moran-_d/rendu/cpp_nibbler/src
//
// Made by moran-_d
// Login   <moran-_d@epitech.net>
//
// Started on  Mon Mar 30 17:32:11 2015 moran-_d
<<<<<<< HEAD
// Last update Fri Apr  3 15:42:14 2015 terran_j
=======
// Last update Fri Apr  3 14:11:15 2015 moran-_d
>>>>>>> c720c18016b65ead1117a2d06e605d0feacc0650
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
  this->buildEvents();
}

Nibbler::~Nibbler()
{}

/*
** *************************************************
** PROCESS *****************************************
** *************************************************
*/

int Nibbler::process()
{
  bool loop = true;
  int key = 0;

  if (this->popSnake(this->map->getX() / 2, this->map->getY() / 2, 0xFF00FF) < 0)
    return (-1);
  this->map->printMap();
  this->ticked = std::chrono::system_clock::now();
  while (loop)
    {
      while (loop == true && (key = this->lib->getEvent()) >= 0)
	{
	  std::cout << "Key received : " << key << std::endl;
	  loop = this->applyEvent(key);
	}
      this->process_snake(this->ticked);
      this->lib->refreshImg(this->map->getMap());
    }
  lib->closeLib();
  return (0);
}

/*
** *************************************************
** EVENTS ******************************************
** *************************************************
*/

bool Nibbler::applyEvent(int key)
{
  if (key == 27)
    return eventQuit();
  else if (this->events.find(key) != this->events.end())
    (this->* this->events[key])();
  for (std::list<Snake*>::iterator it = this->snakes.begin(); it != this->snakes.end(); ++it)
    (*it)->tryDirKey(key);
  return true;
}

void Nibbler::buildEvents()
{
  this->events[8] = &Nibbler::eventPopSnake;
  this->events[32] = &Nibbler::eventPause;
}

bool Nibbler::eventQuit()
{
  return false;
}

bool Nibbler::eventPopSnake()
{
  bool t = this->paused;

  this->paused = false;
  this->popNewSnake();
  this->paused = t;
  return true;
}

bool Nibbler::eventPause()
{
  this->paused = !this->paused;
  return true;
}

/*
** *************************************************
** PROCESS SNAKE ***********************************
** *************************************************
*/

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
  std::chrono::system_clock::time_point cur = std::chrono::system_clock::now();
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
	  this->popSnake(obj[0], obj[1], 0x00FF00);
	  tries = -1;
	  while (tries < 0)
	    tries = this->lib->getEvent();
	  this->snakes.front()->setLeft(tries);
	  tries = -1;
	  while (tries < 0)
	    tries = this->lib->getEvent();
	  this->snakes.front()->setRight(tries);
	}
      ++tries;
    }
  this->ticked += (std::chrono::system_clock::now() - cur);
}

void Nibbler::reset_snake() const
{
  for (std::list<Snake*>::const_iterator it = this->snakes.begin(); it != this->snakes.end(); ++it)
    it = it;
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
	  //  this->map->printMap();
	}
      it = next;
    }
  last = cur;
}

int Nibbler::process()
{
  bool loop = true;
  int key = 0;

  if (this->popSnake(this->map->getX() / 2, this->map->getY() / 2, 0xFF00FF) < 0)
    return (-1);
  //  this->map->printMap();
  this->ticked = std::chrono::system_clock::now();
  while (loop)
    {
      while (loop == true && (key = this->lib->getEvent()) >= 0)
	{
	  std::cout << "Key received : " << key << std::endl;
	  loop = this->applyEvent(key);
	}
      this->process_snake(this->ticked);
      this->lib->refreshImg(this->map->getMap());
    }
  lib->closeLib();
  return (0);
}
