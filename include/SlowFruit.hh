//
// SlowFruit.hh for SlowFruit in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Fri Apr  3 17:49:27 2015 moran-_d
// Last update Sat Apr  4 20:10:25 2015 moran-_d
//

#ifndef SLOWFRUIT_H_
#define SLOWFRUIT_H_

#include "Fruit.hh"

class SlowFruit : public Fruit {
public:
  SlowFruit();
  ~SlowFruit();

private:
  SlowFruit &operator=(SlowFruit const &);
  SlowFruit(const SlowFruit &);
  SlowFruit(const SlowFruit &&);  

public:
  void turn(Map *);
  void use(Map *map, Snake *snake, unsigned int *);
};

#endif
