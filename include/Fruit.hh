//
// Fruit.hh for Fruit in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Thu Mar 26 15:27:29 2015 moran-_d
// Last update Sat Apr  4 19:58:29 2015 moran-_d
//

#ifndef FRUIT_H_
#define FRUIT_H_

#include "Item.hh"

class Fruit : public Item {
protected:
  int pos[2];

private:
  Fruit &operator=(Fruit const &);
  Fruit(const Fruit &);
  Fruit(const Fruit &&);

public:
  Fruit();
  ~Fruit();
  
public:
  virtual int pop(Map *);
  virtual void turn(Map *);
  virtual void use(Map *, Snake *, unsigned int *);
};

#endif
