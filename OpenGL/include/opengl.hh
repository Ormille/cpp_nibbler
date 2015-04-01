//
// opengl.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:05:08 2015 Julie Terranova
// Last update Wed Apr  1 18:23:31 2015 terran_j
//

#ifndef OPENGL_HH__
# define OPENGL_HH__

#include "IObjGraph.hpp"

class OpenGL : public IObjGraph
{
public:
  OpenGL();
  ~OpenGL();

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
