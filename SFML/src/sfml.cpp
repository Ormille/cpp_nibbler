//
// sfml.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:03 2015 Julie Terranova
// Last update Fri Apr  3 15:31:39 2015 terran_j
//

#include <iostream>
#include "sfml.hh"

SFML::SFML()
{}

SFML::~SFML()
{}

int	SFML::initLib(unsigned int x, unsigned int y)
{
  sf::RenderWindow *n;

  if (x * SIZE > 1800 || y * SIZE > 1000)
    {
      std::cerr << "Too hight parameters, try again." << std::endl;
      return (-1);
    }

  n = new sf::RenderWindow(sf::VideoMode(x * SIZE, y * SIZE), "Nibbler SFML",
			   sf::Style::Titlebar | sf::Style::Close);
  this->_window = n;
  this->_x = x;
  this->_y = y;

  // load des textures:
  sf::Texture *texture = new sf::Texture();

  if (!texture->loadFromFile("SFML/textures/background.png"))
    return (-1);
  sf::Sprite background(*texture);
  this->_background = background;

  // if (!texture->loadFromFile("SFML/textures/bords.png", sf::IntRect(0, 0, SIZE, SIZE)))
  //   return;
  // sf::Sprite bords(*texture);
  // this->_bords = bords;

  // if (!texture->loadFromFile("SFML/textures/snake.png", sf::IntRect(0, 0, SIZE, SIZE)))
  //   return;
  // sf::Sprite snake(*texture);
  // this->_snake = snake;

  // if (!texture->loadFromFile("SFML/textures/tete.png", sf::IntRect(0, 0, SIZE, SIZE)))
  //   return;
  // sf::Sprite tete(*texture);
  // this->_tete = tete;

  // if (!texture->loadFromFile("SFML/textures/queue.png", sf::IntRect(0, 0, SIZE, SIZE)))
  //   return;
  // sf::Sprite queue(*texture);
  // this->_queue = queue;

  // if (!texture->loadFromFile("SFML/textures/fruit1.png", sf::IntRect(0, 0, SIZE, SIZE)))
  //   return;
  // sf::Sprite fruit1(*texture);
  // this->_fruit1 = fruit1;

  return (0);
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
  this->_background.setPosition(0, 0);
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
  // clean textures en mémoire:
  //  delete(this->_background);
}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "SFML loaded."<< std::endl;
  return (new SFML());
}
