//
// nibbler.cpp for nibbler in /home/moran-_d/rendu/cpp_nibbler/src
//
// Made by moran-_d
// Login   <moran-_d@epitech.net>
//
// Started on  Mon Mar 30 17:32:11 2015 moran-_d
// Last update Sat Apr  4 23:01:57 2015 moran-_d
//

#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <chrono>
#include <iostream>
#include "nibbler.hh"
#include "BigFruit.hh"
#include "SpeedFruit.hh"
#include "SlowFruit.hh"
#include "ScoreFruit.hh"
#include "Portal.hh"

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
  this->buildItems();
  this->ticked = std::chrono::system_clock::now();
  while (loop)
    {
      while (loop == true && (key = this->lib->getEvent()) >= 0)
	{
	  loop = this->applyEvent(key);
	}
      this->process_snake(this->ticked);
      if (this->paused == false)
	this->process_items();
      this->lib->refreshImg(this->map->getMap());
      if (this->snakes.empty())
	loop = false;
    }
  lib->closeLib();
  return (0);
}

/*
** *************************************************
** ITEMS* ******************************************
** *************************************************
*/

void Nibbler::process_items() const
{
  for (auto it = this->items->begin(); it != this->items->end(); ++it)
    ((*it).second)->turn(this->map);
}

void Nibbler::buildItems()
{
  this->map->fillRandomEmptySquareWith(10);
  (*(this->items))[-1] = new Fruit();
  (*(this->items))[-1]->pop(this->map);
  (*(this->items))[-2] = new BigFruit();
  (*(this->items))[-4] = new SpeedFruit();
  (*(this->items))[-5] = new SlowFruit();
  (*(this->items))[-6] = new ScoreFruit();
  (*(this->items))[-100] = new Portal();
  (*(this->items))[-100]->pop(this->map);
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

bool Nibbler::eventQuit() const
{
  return false;
}

bool Nibbler::eventPopSnake()
{
  std::stringstream st;
  bool t = this->paused;

  st << "A savage snake has appeared ! ID=" << (this->snakeCount + 1);
  this->lib->affText(st.str());
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
      obj[0] = (random() % (this->map->getX() - 4)) + 2;
      obj[1] = (random() % (this->map->getY() - 4)) + 2;
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

void Nibbler::remove_snake(std::list<Snake*>::iterator it)
{
  std::stringstream st;

  st << "Serpent N" << (*it)->getId() << " is dead." << std::endl
     << "\t Score : " << (*it)->getScore() + (*it)->getTurn();
  this->lib->affText(st.str());
  this->snakes.erase(it);
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
	    this->remove_snake(it);
	}
      it = next;
    }
  last = cur;
}
