//
// ScoreFruit.hh for ScoreFruit in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 17:49:27 2015 moran-_d
// Last update Sat Apr  4 21:13:26 2015 moran-_d
//

#ifndef SCOREFRUIT_H_
#define SCOREFRUIT_H_

#include "Fruit.hh"

class ScoreFruit : public Fruit {
public:
  ScoreFruit();
  ~ScoreFruit();

private:
  ScoreFruit &operator=(ScoreFruit const &);
  ScoreFruit(const ScoreFruit &);
  ScoreFruit(const ScoreFruit &&);

public:
  void turn(Map *);
  void use(Map *map, Snake *snake, unsigned int *);
};

#endif
