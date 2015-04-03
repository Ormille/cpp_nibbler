//
// Cube.hh for  in /home/le-gue_n/Documents/tek2/cpp_nibbler/OpenGL/include
//
// Made by le-gue_n
// Login   <le-gue_n@epitech.net>
//
// Started on  Fri Apr  3 15:55:08 2015 le-gue_n
// Last update Fri Apr  3 15:55:10 2015 le-gue_n
//

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
  ~Cube();

  void	drawCube(int x, int y, std::tuple<int, int, int> rgb);
  void	drawMapItems(int **map);
  void	drawSnake(int x, int y, int nb);
  void	drawOther(int x, int y, int nb);
};

#endif
