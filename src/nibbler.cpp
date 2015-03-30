//
// nibbler.cpp for nibbler in /home/moran-_d/rendu/cpp_nibbler/src
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Mon Mar 30 17:32:11 2015 moran-_d
// Last update Mon Mar 30 17:49:48 2015 moran-_d
//

#include "nibbler.hh"

Nibbler::Nibbler(unsigned int x, unsigned int y, IObjGraph *lib)
{
  this->map = new Map(x, y);
  this->lib = lib;
}

Nibbler::~Nibbler()
{}

int Nibbler::process()
{
  return (0);
}
