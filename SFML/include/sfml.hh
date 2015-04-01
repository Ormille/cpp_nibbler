//
// sfml.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:57 2015 Julie Terranova
// Last update Wed Apr  1 15:31:09 2015 Julie Terranova
//

#ifndef SFML_HH__
# define SFML_HH__

#include <SFML/Window.hpp>
#include "IObjGraph.hpp"

class SFML : public IObjGraph
{
public:
  SFML();
  ~SFML();

private:
  void initLib(unsigned int x, unsigned int y);
  int getEvent();
  void refreshImg(int **map);
  void affText(const std::string &toAff);
  void closeLib();

  sf::Window _window;
  int _x;
  int _y;
};

#endif
