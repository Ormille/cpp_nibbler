//
// Snake.hh for snake in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Thu Mar 26 15:05:37 2015 moran-_d
// Last update Fri Apr  3 00:15:50 2015 moran-_d
//

#ifndef SNAKE_H_
#define SNAKE_H_

#include <chrono>
#include <array>
#include <map>
#include <deque>

#define SNAKE_WAIT (std::chrono::milliseconds(1000))

class Item;
class Map;

class Snake {
private:
  bool alive;
  std::chrono::milliseconds counter;

private:
  bool moved;
  double speed_modifier;
  int direction;
  std::deque<std::array<unsigned int, 2>> pos;

private:
  std::map<int, Item*> *items;
  Map *map;

private:
  int left_key;
  int right_key;

private:
  int id;
  int turn;
  int score;
  int color;

public:
  Snake(std::map<int, Item*> *items, Map *map, unsigned int x, unsigned int y, int color, int id);
  ~Snake();

private:
  int getNextCell(unsigned int *objective) const;
  void back();

public:
  void reduce_tail();
  int harakiri();
  int tryDirKey(int key);
  int advance();

public:
  int getScore() const;
  int getColor() const;
  void setLeft(int const key);
  void setRight(int const key);
  std::chrono::milliseconds getCounter() const;
  void setCounter(const std::chrono::milliseconds&);
  double getSpeedModifier() const;
};

#endif
