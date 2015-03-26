//
// minilibx.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 16:59:35 2015 Julie Terranova
// Last update Thu Mar 26 10:50:39 2015 moran-_d
//

#ifndef MINILIBX_HH__
# define MINILIBX_HH__

#include "IObjGraph.hh"

class Minilibx : public IObjGraph {
public:
  Minilibx();
  ~Minilibx();

private:
  void initLib();
  int getEvent();
  void refreshImg();
  void aff();
};

#endif
