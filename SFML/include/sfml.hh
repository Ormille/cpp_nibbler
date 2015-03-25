//
// sfml.hh for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:57 2015 Julie Terranova
// Last update Wed Mar 25 11:51:04 2015 Julie Terranova
//

#ifndef SFML_HH__
# define SFML_HH__

#include "IObjGraph.hh"

class SFML : public IObjGraph
{
  SFML();
  ~SFML();

  void initLib();
  int getEvent();
  void refreshImg();
  void aff();
};

#endif
