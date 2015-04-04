//
// minilibx.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 16:59:35 2015 Julie Terranova
// Last update Fri Apr  3 15:38:32 2015 le-gue_n
//

#ifndef NCURSES_HH__
# define NCURSES_HH__

#include <ncurses.h>
#include "IObjGraph.hpp"

class nCurses: public IObjGraph 
{
public:
  nCurses();
  ~nCurses();

  int	initLib(unsigned int x, unsigned int y);
  int	getEvent();
  void	getTheChar(int nb);
  void	putSnake(int nb);
  void	putItems(int nb);
  void	refreshImg(int **map);
  void	affText(const std::string &toAff);
  void	closeLib();

private:
  int		_x;
  int		_y;
  WINDOW	*_win;
};

#endif
