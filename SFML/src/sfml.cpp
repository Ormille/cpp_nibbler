//
// sfml.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:03 2015 Julie Terranova
// Last update Thu Mar 26 10:48:45 2015 moran-_d
//

#include "sfml.hh"

SFML::SFML()
{}

SFML::~SFML()
{}

void	SFML::initLib()
{

}

int	SFML::getEvent()
{
  return (0);
}

void	SFML::refreshImg()
{

}

void	SFML::aff()
{

}

extern "C"
IObjGraph *nibbler_entry_point()
{
  return (new SFML());
}
