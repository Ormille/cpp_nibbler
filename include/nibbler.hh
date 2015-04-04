/*
** nibbler.h for nibbler in /home/terran_j/rendu/cpp_nibbler
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Mar 23 18:37:22 2015 Julie Terranova
// Last update Sat Apr  4 22:09:37 2015 moran-_d
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

class Nibbler;

typedef bool (Nibbler::*eventPtr)();

class Nibbler {
private:
  std::list<Snake*> snakes;
  std::map<int, Item*> *items;
  std::map<int, eventPtr> events;
  IObjGraph *lib;
  Map *map;

private:
  Nibbler &operator=(Nibbler const &);
  Nibbler(const Nibbler &);
  Nibbler(const Nibbler &&);

private:
  std::chrono::system_clock::time_point ticked;
  bool paused;
  unsigned int snakeCount;

public:
  Nibbler(unsigned int x, unsigned int y, IObjGraph *lib);
  ~Nibbler();

public:
  int process();

private:
  void process_items() const;
  void buildItems();

public:
  bool applyEvent(int key);

private:
  void buildEvents();
  bool eventQuit() const;
  bool eventPopSnake();
  bool eventPause();

private:
  int popSnake(unsigned int, unsigned int, int);
  void popNewSnake();
  void reset_snake() const;
  void remove_snake(std::list<Snake*>::iterator it);
  void process_snake(std::chrono::system_clock::time_point &last);
};

#endif
