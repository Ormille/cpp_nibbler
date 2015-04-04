//
// sfml.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:57 2015 Julie Terranova
// Last update Sat Apr  4 22:57:59 2015 terran_j
//

#ifndef SFML_HH__
# define SFML_HH__

#include <map>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include "IObjGraph.hpp"

#define SIZE 35

class SFML;

typedef void (SFML::*mapFPtr)(int, int);

class SFML : public IObjGraph
{
public:
  SFML();
  ~SFML();

private:
  std::map<int, mapFPtr> _mapf;
  std::map<int, int> _mape;
  int _span;

  SFML &operator=(SFML const &);
  SFML(const SFML &);
  SFML(const SFML &&);

  int initLib(unsigned int x, unsigned int y);
  int getEvent();
  void refreshImg(int **map);
  void affText(const std::string &toAff);
  void closeLib();

  void buildMaps();
  void fbords(int x, int y);
  void ftete(int x, int y);
  void fsnake(int x, int y);
  void fqueue(int x, int y);
  void fswimm(int x, int y);
  void fportal(int x, int y);
  void ffruit1(int x, int y);
  void ffruit2(int x, int y);
  void ffruit3(int x, int y);
  void ffruit4(int x, int y);
  void ffruit5(int x, int y);
  void ffruit6(int x, int y);
  void ffruit7(int x, int y);
  void ffruit8(int x, int y);

  sf::RenderWindow *_window;
  int _x;
  int _y;
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
  sf::Text _txt;
};

#endif
