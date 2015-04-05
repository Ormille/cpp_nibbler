//
// Grid.hh for  in /home/le-gue_n/Documents/tek2/cpp_nibbler/OpenGL/include
//
// Made by le-gue_n
// Login   <le-gue_n@epitech.net>
//
// Started on  Fri Apr  3 15:55:18 2015 le-gue_n
// Last update Fri Apr  3 15:55:19 2015 le-gue_n
//

#ifndef GRID_HH_
#define GRID_HH_

class	GridInfos
{
private:
  float	mapWidth;
  float	mapHeight;
  float	sizeL;
  float	grid;

  GridInfos(const GridInfos &);
  GridInfos(const GridInfos &&);
  GridInfos &operator=(const GridInfos &);
public:
  GridInfos(int mapW, int mapH);
  ~GridInfos();

  int	getMapWidth() const;
  int	getMapHeigth() const;

  void	draw(int **map);
  void	drawLines(float valEnd, float valDraw, bool tf);
};

#endif
