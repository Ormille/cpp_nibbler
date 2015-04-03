
    
#ifndef CUBE_HH_
#define CUBE_HH_

#include <tuple>
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
  
  void	drawSquare();
  void	drawCube(int x, int y, std::tuple<int, int, int> rgb);
  void	drawMapItems(int **map);
  void	drawSnake(int x, int y, int nb);
  void	drawOther(int x, int y, int nb);
};

#endif