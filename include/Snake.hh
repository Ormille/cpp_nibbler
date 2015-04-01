//
// Snake.hh for snake in /home/moran-_d/rendu/cpp_nibbler
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Thu Mar 26 15:05:37 2015 moran-_d
// Last update Wed Apr  1 16:15:22 2015 moran-_d
//

#ifndef SNAKE_H_
#define SNAKE_H_

#include <array>
#include <map>
#include <deque>

class Item;
class Map;

class Snake {
private:
  bool alive;
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
  void harakiri();
  int tryDirKey(int key);
  int advance();

public:
  int getScore() const;
  int getColor() const;
  void setLeft(int const key);
  void setRight(int const key);
};

#endif
