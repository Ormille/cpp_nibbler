/*
** nibbler.h for nibbler in /home/terran_j/rendu/cpp_nibbler
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Mar 23 18:37:22 2015 Julie Terranova
// Last update Fri Apr  3 11:49:56 2015 moran-_d
*/

#ifndef NIBBLER_HH_
# define NIBBLER_HH_

#include <chrono>
#include <list>
#include <map>
#include "Snake.hh"
#include "Item.hh"
#include "Map.hh"
#include "IObjGraph.hpp"

class Nibbler {
private:
  std::list<Snake*> snakes;
  std::map<int, Item*> *items;
  IObjGraph *lib;
  Map *map;
  std::chrono::system_clock::time_point ticked;
  bool paused;

private:
  unsigned int snakeCount;

private:
  int popSnake(unsigned int, unsigned int, int);
  void popNewSnake();
  void reset_snake() const;
  void process_snake(std::chrono::system_clock::time_point &last);

public:
  Nibbler(unsigned int x, unsigned int y, IObjGraph *lib);
  ~Nibbler();

public:
  int init();
  bool applyEvent(int key);
  int process();
};

#endif
