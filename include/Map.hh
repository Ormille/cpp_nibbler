//
// Map.hh for map in /home/moran-_d/rendu/cpp_nibbler/include
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Mon Mar 30 15:43:56 2015 moran-_d
// Last update Sat Apr  4 20:00:59 2015 moran-_d
//

#ifndef MAP_HH_
#define MAP_HH_

class Map {
private:
  unsigned int x;
  unsigned int y;
  int **map;

private:
  Map &operator=(Map const &);
  Map(const Map &);
  Map(const Map &&);

public:
  Map(unsigned int x, unsigned int y);
  ~Map();

public:
  void printMap() const;

public:
  int **getMap() const;
  int fillRandomEmptyCellWith(int id, int *obj);
  int fillRandomEmptyCellWith(int id, unsigned int *obj);
  int fillRandomEmptySquareWith(int id);
  int setCell(unsigned int x, unsigned int y, int val);
  int getCell(unsigned int x, unsigned int y) const;
  int getX() const;
  int getY() const;
};

#endif
