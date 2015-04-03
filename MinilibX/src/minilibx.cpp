//
// minilibx.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 16:58:47 2015 Julie Terranova
// Last update Fri Apr  3 15:38:08 2015 le-gue_n
//

#include <iostream>
#include <stdio.h>
#include "minilibx.hh"

Minilibx::Minilibx()
{}

Minilibx::~Minilibx()
{}

int    Minilibx::initLib(unsigned int x, unsigned int y)
{
  this->_x = x;
  this->_y = y;
}

int     Minilibx::getEvent()
{
  return (0);
}

void    Minilibx::refreshImg(int **map)
{
  map = map; // a virer
}

void    Minilibx::affText(const std::string &toAff)
{
  std::cout << toAff << std::endl; // a virer
}

void    Minilibx::closeLib()
{

}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "Minilibx loaded" << std::endl;
  return (new Minilibx());
}
