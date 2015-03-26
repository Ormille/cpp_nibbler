//
// opengl.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:04:19 2015 Julie Terranova
// Last update Thu Mar 26 10:49:12 2015 moran-_d
//

#include <stdio.h>
#include "opengl.hh"

OpenGL::OpenGL()
{}

OpenGL::~OpenGL()
{}

void    OpenGL::initLib()
{

}

int    OpenGL::getEvent()
{
  return (0);
}

void    OpenGL::refreshImg()
{

}

void    OpenGL::aff()
{

}

extern "C"
IObjGraph *nibbler_entry_point()
{
  return (new OpenGL());
}
