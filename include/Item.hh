//
// Items.hh for Items in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Thu Mar 26 15:23:49 2015 moran-_d
// Last update Mon Mar 30 17:29:30 2015 moran-_d
//

#ifndef ITEM_H_
#define ITEM_H_

#include "Map.hh"
#include "Snake.hh"

class Item {
protected:
  bool exist;
  int lifespan;

protected:
  Item();
  virtual ~Item() {};

public:
  virtual int pop(Map &) = 0;
  virtual void turn(Map &) = 0;
  virtual void use(Snake &) = 0;
};

#endif
