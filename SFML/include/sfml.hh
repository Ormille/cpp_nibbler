//
// sfml.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:57 2015 Julie Terranova
// Last update Sat Apr  4 18:53:31 2015 terran_j
//

#ifndef SFML_HH__
# define SFML_HH__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "IObjGraph.hpp"

#define SIZE 35

class SFML : public IObjGraph
{
public:
  SFML();
  ~SFML();

private:
  int initLib(unsigned int x, unsigned int y);
  int getEvent();
  void refreshImg(int **map);
  void affText(const std::string &toAff);
  void closeLib();

  sf::RenderWindow *_window;
  int _x;
  int _y;
  sf::Sprite _background;
  sf::Sprite _bords;
  sf::Sprite _snake;
  sf::Sprite _tete;
  sf::Sprite _queue;
  sf::Sprite _fruit1;
  sf::Sprite _fruit2;
  sf::Sprite _fruit3;
  sf::Sprite _fruit4;
  sf::Sprite _fruit5;
  sf::Sprite _fruit6;
  sf::Sprite _fruit7;
  sf::Sprite _fruit8;
  sf::Sprite _portal;
  sf::Sprite _swimm;
  sf::Music _music;
};

#endif
