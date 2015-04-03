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
  initscr();
  WINDOW * win = stdscr;//newwin(1080, 1920, 0, 0);
  cbreak();
  noecho();
  curs_set(FALSE);
  this->_x = x;
  this->_y = y;
  this->_win = win;
  return (0);
}

int     nCurses::getEvent()
{
  return (wgetch(this->_win));
 // return (0);
}

void    nCurses::refreshImg(int **map)
{
  //map = map; // a virer
  int	x = 0;
  int	y = 0;
  
  while (y < this->_y)
  {
    while (x < this->_x)
    {
      if (map[y][x] > 3)
	mvwvline(this->_win, x, y, '#', 1);
      x++;
    }
   y++; 
  }
}

void    nCurses::affText(const std::string &toAff)
{
  std::cout << toAff << std::endl; // a virer
}

void    nCurses::closeLib()
{
  endwin();
}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "nCurses loaded" << std::endl;
  return (new nCurses());
}
