//
// sfml.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:03 2015 Julie Terranova
// Last update Thu Apr  2 17:24:58 2015 terran_j
//

#include <iostream>
#include "sfml.hh"

SFML::SFML()
{}

SFML::~SFML()
{}

void	SFML::initLib(unsigned int x, unsigned int y)
{
  sf::Window *n;

  n = new sf::Window(sf::VideoMode(x, y), "Nibbler SFML",
	     sf::Style::Titlebar | sf::Style::Resize
	     | sf::Style::Close);
  this->_window = n;
  this->_x = x;
  this->_y = y;


  /* load les textures pr:
     0 - vide / background
     1 _ tete
     2 - corps
     ... voir todo!
     negatif - bouffe
  */
}

int	SFML::getEvent()
{
  sf::Event Event;

  while (this->_window->pollEvent(Event))
    {
      if (Event.type == sf::Event::Closed)
	return (36);
      if (Event.type == sf::Event::KeyPressed)
	return Event.key.code;
    }
  return (0);
}

void	SFML::refreshImg(int **map)
{
  map = map; // atej
}

void	SFML::affText(const std::string &toAff)
{
  std::cout << toAff << std::endl; // atej
}

void    SFML::closeLib()
{
  this->_window->close();
  // clean textures en mémoire
}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "SFML loaded."<< std::endl;
  return (new SFML());
}
