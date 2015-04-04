//
// ncurses.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 16:58:47 2015 Julie Terranova
// Last update Fri Apr  3 15:48:37 2015 terran_j
//

#include <iostream>
#include <stdio.h>
#include "nCurses.hh"

nCurses::nCurses()
{}

nCurses::~nCurses()
{}

int    nCurses::initLib(unsigned int x, unsigned int y)
{
  unsigned int xtmp = 0;
  unsigned int ytmp = 0;
  
  initscr();
  getmaxyx(stdscr, xtmp, ytmp);
  if (x > xtmp || y > ytmp)
    return (-1);
  cbreak();
  noecho();
  curs_set(FALSE);
  this->_x = x;
  this->_y = y;
  this->_win = newwin(x, y * 2, 0, 0);
  wtimeout(this->_win, 1);
  return (0);
}

int     nCurses::getEvent()
{
  int ch = -1;

  if ((ch = wgetch(this->_win)))
    return (ch);
  return (ch);
}

void	nCurses::putItems(int x, int y, int nb)
{
  if (nb == -1)
    mvprintw(x, y, "&");
  else
    mvprintw(x, y, "x");
    
}

void	nCurses::putSnake(int x, int y, int nb)
{
  if (nb == 1)
    mvprintw(x, y, "@");
  else if (nb == 3)
    mvprintw(x, y, "o");
  else
    mvprintw(x, y, "O");
}

void    nCurses::refreshImg(int **map)
{
  //map = map; // a virer
  int	x = 0;
  int	y = 0;

  wclear(this->_win);
  while (y < this->_y )
  {
    x = 0;
    while (x < this->_x)
    {
      if (map[y][x] < 0)
	this->putItems(x, y, map[y][x]);
      else if (map[y][x] <= 3)
	this->putSnake(x, y, map[y][x]);
      else
	mvwvline(this->_win, x, y, '#', 1);
      x++;
    }
   y++; 
  }
  wrefresh(this->_win);
}

void    nCurses::affText(const std::string &toAff)
{
  std::cout << toAff << std::endl; // a virer
}

void    nCurses::closeLib()
{
  endwin();
}
/*
int	main()
{
  nCurses *test = new nCurses();
  unsigned int i;
  unsigned int t;
  unsigned int x = 10;
  unsigned int y = 10;

  int **map = new int*[x];
  for (i = 0; i < x; i++)
    {
      map[i] = new int[y]();
      if (i == 0 || i == x - 1)
        for (t = 0; t < y; t++)
          map[i][t] = 2147483647;
    }
  for (i = 0; i < x; i++)
    {
      map[i][0] = 2147483647;
      map[i][y - 1] = 2147483647;
    }
  test->initLib(10, 10);
 while (test->getEvent() != 27)
 {
  test->refreshImg(map);
 }
  test->closeLib();
}
*/
extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "nCurses loaded" << std::endl;
  return (new nCurses());
}
