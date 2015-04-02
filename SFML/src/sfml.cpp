//
// sfml.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:03 2015 Julie Terranova
// Last update Thu Apr  2 19:47:26 2015 terran_j
//

#include <iostream>
#include "sfml.hh"

SFML::SFML()
{}

SFML::~SFML()
{}

void	SFML::initLib(unsigned int x, unsigned int y)
{
  sf::RenderWindow *n;

  n = new sf::RenderWindow(sf::VideoMode(x, y), "Nibbler SFML",
			   sf::Style::Titlebar | sf::Style::Close);
  this->_window = n;
  this->_x = x;
  this->_y = y;

  // load des textures:
  sf::Texture texture;
  sf::Sprite sprite;

  if (!texture.loadFromFile("background.png"))
    {
      std::cerr << "Texture file doesn't exist." << std::endl;
      return;
    }
  sprite.setTexture(texture);
  this->_background = sprite;
}

int	SFML::getEvent()
{
  sf::Event Event;

  while (this->_window->pollEvent(Event))
    {
      if (Event.type == sf::Event::Closed)
	return (27);
      else if (Event.type == sf::Event::KeyPressed) // -42 si je change pas ca, faire map
	{
	  if (Event.key.code == 71)
	    return (276); // gauche
	  else if (Event.key.code == 72)
	    return (275); // droite
	  else if (Event.key.code == 73)
	    return (273); // haut
	  else if (Event.key.code == 74)
	    return (274); // bas
	  else if (Event.key.code == 36)
	    return (27); // echap
	  else if (Event.key.code == 57)
	    return (32); // space
	  else if (Event.key.code == 59)
	    return (8); // del
	  else
	    return Event.key.code;
	}
    }
  return (-1);
}

void	SFML::refreshImg(int **map)
{
  map = map; // atej

  // clear
  this->_window->clear(sf::Color::Black);

  // draw
  this->_window->draw(this->_background);

  // display
  this->_window->display();
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
