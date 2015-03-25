/*
** main.c for nibbler in /home/terran_j/rendu/cpp_nibbler
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Mar 23 18:36:43 2015 Julie Terranova
// Last update Wed Mar 25 12:07:44 2015 Julie Terranova
*/

#include "nibbler.hh"
#include "IObjGraph.hh"

int	main()
{
  IObjGraph *test;

  test = new IObjGraph();
  test->initLib();
  while (test->getEvent())
    {
      test->refreshImg();
      test->aff();
    }
  return (0);
}
