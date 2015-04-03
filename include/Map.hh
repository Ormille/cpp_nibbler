//
// Map.hh for map in /home/moran-_d/rendu/cpp_nibbler/include
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Mon Mar 30 15:43:56 2015 moran-_d
// Last update Fri Apr  3 15:02:06 2015 moran-_d
//

#ifndef MAP_HH_
#define MAP_HH_

class Map {
private:
  unsigned int x;
  unsigned int y;
  int **map;

public:
  Map(unsigned int x, unsigned int y);
  ~Map();

public:
  void printMap();

public:
  int **getMap() const;
  int fillRandomEmptyCellWith(int id, int *obj);
  int setCell(unsigned int x, unsigned int y, int val);
  int getCell(unsigned int x, unsigned int y) const;
  int getX() const;
  int getY() const;
};

#endif
