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
//#include <stdio.h>

#include <curses.h>
#include <map>
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
  if (x + 2 > xtmp || y + 2 > ytmp)
    {
      endwin();
      return (-1);
    }
  cbreak();
  noecho();
  curs_set(FALSE);
  this->_x = x;
  this->_y = y;
  this->_win = newwin(y + 2, x * 2 + 3, 0, 0);
  keypad(this->_win, TRUE);
  wtimeout(this->_win, 100);
  return (0);
}

int     nCurses::getEvent()
{
  int ch = -1;
  std::map<int, int> keys;

  keys[KEY_LEFT] = 276;
  keys[KEY_RIGHT] = 275;
  keys[KEY_UP] = 273;
  keys[KEY_DOWN] = 274;
  keys[KEY_BACKSPACE] = 8;
  keys[27] = 27;
  keys[static_cast<int>(' ')] = 32;
  ch = wgetch(this->_win);
  for (std::map<int, int>::iterator it = keys.begin(); it != keys.end(); ++it)
    {
      if ((*it).first == ch)
	return ((*it).second);
    }
  return (ch);
}

void	nCurses::putItems(int nb)
{
  std::map<int, char> items;

  items[-1] = 'F';
  items[-2] = 'f';
  items[-4] = 'S';
  items[-5] = 's';
  items[-100] = 'x';
  items[10] = '~';
  for (std::map<int, char>::iterator it = items.begin(); it != items.end(); ++it)
    {
      if ((*it).first == nb)
	{
	  waddch(this->_win, (*it).second);
	//  if ((*it).first != 10)
	    waddch(this->_win, ' ');
	 /* else
	    waddch(this->_win, '~');*/
	  return;
	}
    }
}

void	nCurses::putSnake(int nb)
{
  std::map<int, char> items;

  items[1] = '@';
  items[2] = 'O';
  items[3] = 'o';
  for (std::map<int, char>::iterator it = items.begin(); it != items.end(); ++it)
    {
      if ((*it).first == nb)
	{
	  waddch(this->_win, (*it).second);
	  waddch(this->_win, ' ');
	  return;
	}
    }
}

int	nCurses::notWall(int nb)
{
  if (nb < 0 || nb == 10)
  {
    this->putItems(nb);
    return (true);
  }
  else if (nb > 0 && nb <= 3)
  {
    this->putSnake(nb);
    return (true);
  }
  return (false);
}

void    nCurses::refreshImg(int **map)
{
  int	y = 0;
  int	x;

  wclear(this->_win);
  while (y < this->_y + 2)
    {
      x = 0;
      while (x < this->_x + 2)
	{
	   /* if (map[x][y] < 0 || map[x][y] == 10)
	      this->putItems(map[x][y]);
	    else if (map[x][y] > 0 && map[x][y] <= 3)
	      this->putSnake(map[x][y]);*/
	   if (this->notWall(map[x][y]));
	    else if (/*notWall(map[x][y]) == false && */map[x][y] == 2147483647)
	    {
	      waddch(this->_win, '#');
	      if ((y == 0 || y == this->_y + 1) && (x != 0 && x != this->_x))
		waddch(this->_win, '#');
	    }
	  else
	    {
	      waddch(this->_win, ' ');
	      waddch(this->_win, ' ');
	    }
	    x++;
	}
      waddch(this->_win, '\n');
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
  wclear(this->_win);
  endwin();
  std::cout << "You lost" << std::endl;
}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "nCurses loaded" << std::endl;
  return (new nCurses());
}
