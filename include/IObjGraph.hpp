//
// IObjGraph.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Wed Mar 25 11:30:41 2015 Julie Terranova
// Last update Fri Apr  3 15:30:53 2015 terran_j
//

#ifndef IOBJGRAPH_HH__
# define IOBJGRAPH_HH__

#include <iostream>

class IObjGraph
{
public:
  virtual ~IObjGraph() {};

  virtual int initLib(unsigned int, unsigned int) = 0;
  virtual int getEvent() = 0;
  virtual void refreshImg(int**) = 0;
  virtual void affText(const std::string &) = 0;
  virtual void closeLib() = 0;
};

#endif
