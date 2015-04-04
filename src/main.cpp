/*
** main.c for nibbler in /home/terran_j/rendu/cpp_nibbler
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Mar 23 18:36:43 2015 Julie Terranova
// Last update Sat Apr  4 18:08:45 2015 moran-_d
*/

#include <ctime>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include "nibbler.hh"
#include "IObjGraph.hpp"
#include "DLLoader.hh"

unsigned int strToInt(char *st)
{
  std::stringstream tmp;
  unsigned int x;

  tmp << st;
  tmp >> x;
  return (x);
}

IObjGraph *load_lib(char *st, DLLoader &dll)
{
  IObjGraph *ret;

  if ((dll.LoadDL(st)) < 0)
    return (NULL);
  ret = dll.getIOGInstance();
  if (ret == NULL)
    dll.CloseDL();
  return (ret);
}

Nibbler *load_game(unsigned int x, unsigned int y, IObjGraph *lib)
{
  Nibbler *ret;

  ret = new Nibbler(x, y, lib);
  return (ret);
}

int	main(int argc, char **argv)
{
  IObjGraph *lib;
  DLLoader dll;
  Nibbler *game;
  unsigned int x;
  unsigned int y;

  if (argc < 4)
    {
      std::cout << "Usage: nibbler MapX MapY GraphicLibrary" << std::endl;
      return (-1);
    }
  srandom(time(NULL));
  if ((lib = load_lib(argv[3], dll)) == NULL)
    return (-1);
  if ((x = strToInt(argv[1])) < 10 || x > 100)
    {
      std::cout << "Invalid map width" << std::endl;
      return (0);
    }
  if ((y = strToInt(argv[2])) < 10 || y > 100)
    {
      std::cout << "Invalid map heigth" << std::endl;
      return (0);
    }
  if (lib->initLib(x, y) == -1)
    return (-1);
  game = load_game(x, y, lib);
  game->process();
  dll.CloseDL();
  return (0);
}
