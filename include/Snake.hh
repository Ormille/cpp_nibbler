//
// Snake.hh for snake in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Thu Mar 26 15:05:37 2015 moran-_d
// Last update Mon Mar 30 17:28:48 2015 moran-_d
//

#ifndef SNAKE_H_
#define SNAKE_H_

#include <deque>

class Snake {
private:
  bool alive;
  int score;
  int turn;
  int left_key;
  int right_key;
  int speed_modifier;
  int color;
  int direction;
  std::deque<int[2]> pos;
};

#endif
