//
// SpeedFruit.hh for SpeedFruit in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 17:49:27 2015 moran-_d
// Last update Sat Apr  4 15:50:43 2015 moran-_d
//

#ifndef SPEEDFRUIT_H_
#define SPEEDFRUIT_H_

#include "Fruit.hh"

class SpeedFruit : public Fruit {
public:
  SpeedFruit();
  ~SpeedFruit();

public:
  void turn(Map *);
  void use(Map *map, Snake *snake);
};

#endif
