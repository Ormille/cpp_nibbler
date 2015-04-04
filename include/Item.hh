//
// Items.hh for Items in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Thu Mar 26 15:23:49 2015 moran-_d
// Last update Sat Apr  4 17:14:39 2015 moran-_d
//

#ifndef ITEM_H_
#define ITEM_H_

#include "Map.hh"
#include "Snake.hh"

class Item {
protected:
  int id;
  bool exist;
  int span;

protected:
  Item();
  Item(int id, bool exist, int span) : id(id), exist(exist), span(span) {};
  virtual ~Item() {};

public:
  virtual int pop(Map *) = 0;
  virtual void turn(Map *) = 0;
  virtual void use(Map *, Snake *, unsigned int *) = 0;
};

#endif
