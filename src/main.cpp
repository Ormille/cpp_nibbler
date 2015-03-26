/*
** main.c for nibbler in /home/terran_j/rendu/cpp_nibbler
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Mar 23 18:36:43 2015 Julie Terranova
// Last update Thu Mar 26 11:31:56 2015 moran-_d
*/

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

int	main(int argc, char **argv)
{
  IObjGraph *test;
  DLLoader dll;

  if (argc < 4)
    {
      std::cout << "Usage: nibbler MapX MapY GraphicLibrary" << std::endl;
      return (-1);
    }
  if ((test = load_lib(argv[3], dll)) == NULL)
    return (-1);
  test->initLib();
  while (test->getEvent())
    {
      test->refreshImg();
      test->aff();
    }
  dll.CloseDL();
  return (0);
}
