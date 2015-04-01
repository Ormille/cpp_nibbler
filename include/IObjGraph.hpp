//
// IObjGraph.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Wed Mar 25 11:30:41 2015 Julie Terranova
// Last update Wed Apr  1 14:54:10 2015 moran-_d
//

#ifndef IOBJGRAPH_HH__
# define IOBJGRAPH_HH__

#include <iostream>

class IObjGraph
{
public:
  virtual ~IObjGraph() {};

  virtual void initLib(unsigned int, unsigned int) = 0;
  virtual int getEvent() = 0;
  virtual void refreshImg(int**) = 0;
  virtual void affText(const std::string &) = 0;
  virtual void closeLib() = 0;
};

#endif
