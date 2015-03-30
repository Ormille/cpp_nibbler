/*
** main.c for nibbler in /home/terran_j/rendu/cpp_nibbler
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Mar 23 18:36:43 2015 Julie Terranova
// Last update Mon Mar 30 17:46:48 2015 moran-_d
*/

#include <sstream>
#include <stdlib.h>
#include <iostream>
#include "nibbler.hh"
#include "IObjGraph.hpp"
#include "DLLoader.hh"

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

Nibbler *load_game(char *xc, char *yc, IObjGraph *lib)
{
  Nibbler *ret;
  std::stringstream tmp;
  unsigned int x;
  unsigned int y;

  tmp << xc;
  tmp >> x;
  tmp.str("");
  tmp << yc;
  tmp >> y;
  ret = new Nibbler(x, y, lib);
  return (ret);
}

int	main(int argc, char **argv)
{
  IObjGraph *lib;
  DLLoader dll;
  Nibbler *game;

  if (argc < 4)
    {
      std::cout << "Usage: nibbler MapX MapY GraphicLibrary" << std::endl;
      return (-1);
    }
  if ((lib = load_lib(argv[3], dll)) == NULL)
    return (-1);
  lib->initLib();
  game = load_game(argv[1], argv[2], lib);
  game->process();
  dll.CloseDL();
  return (0);
}
