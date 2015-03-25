//
// opengl.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:05:08 2015 Julie Terranova
// Last update Wed Mar 25 11:51:47 2015 Julie Terranova
//

#ifndef OPENGL_HH__
# define OPENGL_HH__

#include "IObjGraph.hh"

class OpenGL : public IObjGraph
{
  OpenGL();
  ~OpenGL();

  void initLib();
  int getEvent();
  void refreshImg();
  void aff();
};

#endif
