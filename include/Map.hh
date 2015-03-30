//
// Map.hh for map in /home/moran-_d/rendu/cpp_nibbler/include
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Mon Mar 30 15:43:56 2015 moran-_d
// Last update Mon Mar 30 17:36:47 2015 moran-_d
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
  int **getMap() const;
};

#endif
