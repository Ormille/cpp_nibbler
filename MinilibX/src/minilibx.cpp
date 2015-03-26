//
// minilibx.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 16:58:47 2015 Julie Terranova
// Last update Thu Mar 26 10:51:15 2015 moran-_d
//

#include <stdio.h>
#include "minilibx.hh"

Minilibx::Minilibx()
{

}

Minilibx::~Minilibx()
{

}

void    Minilibx::initLib()
{

}

int     Minilibx::getEvent()
{
  return (0);
}

void    Minilibx::refreshImg()
{

}

void    Minilibx::aff()
{

}

extern "C"
IObjGraph *nibbler_entry_point()
{
  return (new Minilibx());
}
