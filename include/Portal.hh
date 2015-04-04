//
// Portal.hh for portal in /home/moran-_d/rendu/cpp_nibbler/include
// 
// Made by moran-_d
// Login   <moran-_d@epitech.net>
// 
// Started on  Sat Apr  4 16:57:16 2015 moran-_d
// Last update Sat Apr  4 20:02:34 2015 moran-_d
//

#ifndef PORTAL_H_
#define PORTAL_H_

#include "Item.hh"

class Portal : public Item {
private:
  unsigned int pos1[2];
  unsigned int pos2[2];

private:
  Portal &operator=(Portal const &);
  Portal(const Portal &);
  Portal(const Portal &&);

public:
  Portal();
  ~Portal();

public:
  virtual int pop(Map *);
  virtual void turn(Map *);
  virtual void _use(Map *, Snake *, unsigned int *) const;
  virtual void use(Map *, Snake *, unsigned int *);
};

#endif
