//
// SpeedFruit.hh for SpeedFruit in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 17:49:27 2015 moran-_d
// Last update Sat Apr  4 20:11:40 2015 moran-_d
//

#ifndef SPEEDFRUIT_H_
#define SPEEDFRUIT_H_

#include "Fruit.hh"

class SpeedFruit : public Fruit {
public:
  SpeedFruit();
  ~SpeedFruit();

private:
  SpeedFruit &operator=(SpeedFruit const &);
  SpeedFruit(const SpeedFruit &);
  SpeedFruit(const SpeedFruit &&);

public:
  void turn(Map *);
  void use(Map *map, Snake *snake, unsigned int *);
};

#endif
