//
// opengl.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:04:19 2015 Julie Terranova
// Last update Wed Apr  1 18:24:25 2015 terran_j
//

#include <iostream>
#include <stdio.h>
#include "opengl.hh"

OpenGL::OpenGL()
{}

OpenGL::~OpenGL()
{}

void    OpenGL::initLib(unsigned int x, unsigned int y)
{
  this->_x = x;
  this->_y = y;
}

int    OpenGL::getEvent()
{
  return (0);
}

void    OpenGL::refreshImg(int **map)
{
  map = map; // a virer
}

void    OpenGL::affText(const std::string &toAff)
{
  std::cout << toAff << std::endl; // a virer
}

void	OpenGL::closeLib()
{

}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "OpenGL loaded." << std::endl;
  return (new OpenGL());
}
