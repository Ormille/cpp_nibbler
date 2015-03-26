//
// opengl.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:05:08 2015 Julie Terranova
// Last update Thu Mar 26 11:25:01 2015 moran-_d
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
  void initLib();
  int getEvent();
  void refreshImg();
  void aff();
};

#endif
