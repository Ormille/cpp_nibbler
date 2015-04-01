//
// sfml.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:03 2015 Julie Terranova
// Last update Wed Apr  1 16:43:17 2015 Julie Terranova
//

#include <iostream>
#include "sfml.hh"

SFML::SFML()
{
  // set la taille des cases?
}

SFML::~SFML()
{
  // clear tout ce qui etait en memoire?
}

void	SFML::initLib(unsigned int x, unsigned int y)
{
  sf::Window *n;
  // afficher une fenetre de x sur y cases
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
     3 - bords
     negatif - bouffe
  */
}

int	SFML::getEvent()
{
  // return la premiere action de ma stack telle quelle
  sf::Event event;
  sf::Window win(sf::VideoMode(10, 10), "Nibbler SFML");

  while (win.pollEvent(event))
    {
      if (event)
	return event.key.code;
    }
  return (0);
}

void	SFML::refreshImg(int **map)
{

}

void	SFML::affText(const std::string &toAff)
{
  toAff = toAff; // atej
}

void    SFML::closeLib()
{
  // fermer fenetre proprement et pe clean ici?
  this->_window.close();
}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "SFML loaded."<< std::endl;
  return (new SFML());
}
