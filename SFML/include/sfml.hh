//
// sfml.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:57 2015 Julie Terranova
// Last update Thu Mar 26 09:52:51 2015 moran-_d
//

#ifndef SFML_HH__
# define SFML_HH__

#include "IObjGraph.hh"

class SFML : public IObjGraph
{
public:
  SFML();
  ~SFML();

private:
  void initLib();
  int getEvent();
  void refreshImg();
  void aff();
};

#endif
