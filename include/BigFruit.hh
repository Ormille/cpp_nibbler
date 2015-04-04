//
// BigFruit.hh for Bigfruit in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 17:49:27 2015 moran-_d
// Last update Sat Apr  4 20:02:15 2015 moran-_d
//

#ifndef BIGFRUIT_H_
#define BIGFRUIT_H_

#include "Fruit.hh"

class BigFruit : public Fruit {
public:
  BigFruit();
  ~BigFruit();

private:
  BigFruit &operator=(BigFruit const &);
  BigFruit(const BigFruit &);
  BigFruit(const BigFruit &&);  

public:
  void turn(Map *);
  void use(Map *map, Snake *snake, unsigned int *);
};

#endif
