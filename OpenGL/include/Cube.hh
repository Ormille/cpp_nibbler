
    
#ifndef CUBE_HH_
#define CUBE_HH_

#include "Grid.hh"

class	Cube
{
private:
  GridInfos	*infos;
  float mapW;
  float mapH;  
  float sizeW;
  float sizeH;
public:
  Cube(int mapW, int mapH);
  /*Cube(const Cube &);
  Cube	&operator=(const Cube &);*/
  ~Cube();
  
  void	drawCube();
  void	drawSquare();
};

#endif