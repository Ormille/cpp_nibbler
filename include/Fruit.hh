//
// Fruit.hh for Fruit in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Thu Mar 26 15:27:29 2015 moran-_d
// Last update Fri Apr  3 15:05:09 2015 moran-_d
//

#ifndef FRUIT_H_
#define FRUIT_H_

#include "Item.hh"

class Fruit : public Item {
private:
  int pos[2];

public:
  Fruit();
  ~Fruit();
  
public:
  int pop(Map *);
  void turn(Map *);
  void use(Map *, Snake *);
};

#endif
