//
// ncurses.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 16:58:47 2015 Julie Terranova
// Last update Fri Apr  3 15:48:37 2015 terran_j
//

#include <unistd.h>

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

  //wrefresh(this->_win);
  //wclear(this->_win);
  ch = wgetch(this->_win);
  //sleep(2);
//   mvwprintw( this->_win, 5, 5, "%d", ch);
  if (ch == KEY_LEFT)
  {
//     mvwprintw( this->_win, 0, 0, "trolololololo %d", ch);
    return (275);
  }
  if (ch == KEY_RIGHT)
    return (276);
  return (-1);
}

void	nCurses::putItems(int x, int y, int nb)
{
  x = x;
  y = y;
  if (nb == -1)
    waddch(this->_win, '&');
  else
    waddch(this->_win, 'x');
  waddch(this->_win, ' ');//x, y, '#', 1);
}

void	nCurses::putSnake(int x, int y, int nb)
{
  x =x;
  y=y; // virer
  if (nb == 1)
    waddch(this->_win, '@');
  else if (nb == 2)
    waddch(this->_win, 'O');
  else
    waddch(this->_win, 'o');
  waddch(this->_win, ' ');//x, y, '#', 1);
}

void    nCurses::refreshImg(int **map)
{
  map = map;

  int	y = 0;
  int	x;
  wclear(this->_win);
  while (y < this->_y + 2)
  {
    x = 0;
    while (x < this->_x + 2)
    {
      if (map[x][y] < 0)
	this->putItems(x, y, map[x][y]);
      else if (map[x][y] > 0 && map[x][y] <= 3)
	this->putSnake(x, y, map[x][y]);
      else if (map[x][y] == 2147483647)
      {
	waddch(this->_win, '#');//x, y, '#', 1);
	if ((y == 0 || y == this->_y + 1) && (x != 0 && x != this->_x))
	  waddch(this->_win, '#');//x, y, '#', 1);
      }
      else
      {
	waddch(this->_win, ' ');//x, y, '#', 1);
	waddch(this->_win, ' ');//x, y, '#', 1);
      }
      x++;
    }
	waddch(this->_win, '\n');//x, y, '#', 1);
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
