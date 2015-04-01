//
// minilibx.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 16:59:35 2015 Julie Terranova
// Last update Wed Apr  1 18:26:17 2015 terran_j
//

#ifndef MINILIBX_HH__
# define MINILIBX_HH__

#include "IObjGraph.hpp"

class Minilibx : public IObjGraph {
public:
  Minilibx();
  ~Minilibx();

private:
  void initLib(unsigned int x, unsigned int y);
  int getEvent();
  void refreshImg(int **map);
  void affText(const std::string &toAff);
  void closeLib();

  int _x;
  int _y;
};

#endif
