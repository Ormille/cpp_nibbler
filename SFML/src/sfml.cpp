//
// sfml.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:03 2015 Julie Terranova
// Last update Wed Apr  1 18:31:42 2015 terran_j
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
	     | sf::Style::Close/* | sf::Style::Default*/);
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
  // return la premiere action de ma stack telle quelle
  sf::Event event;
  // sf::Window win(sf::VideoMode(10, 10), "Nibbler SFML");

  while (this->_window->pollEvent(event))
    {
      if (event.key.code != 45454545)
	return event.key.code;
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
  // fermer fenetre proprement et clean tout ce qui etait en memoire
  this->_window->close();
}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "SFML loaded."<< std::endl;
  return (new SFML());
}
