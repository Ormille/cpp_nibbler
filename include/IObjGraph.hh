//
// IObjGraph.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Wed Mar 25 11:30:41 2015 Julie Terranova
// Last update Wed Mar 25 11:50:50 2015 Julie Terranova
//

#ifndef IOBJGRAPH_HH__
# define IOBJGRAPH_HH__

#include <iostream>

class IObjGraph
{
public:
  virtual ~IObjGraph();

  virtual void initLib() = 0;
  virtual int getEvent() = 0;
  virtual void refreshImg() = 0;
  virtual void aff() = 0;
};

#endif
