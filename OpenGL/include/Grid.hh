#ifndef GRID_HH_
#define GRID_HH_

class	GridInfos
{
private:
  float	mapWidth;
  float	mapHeight;
  float	sizeL;
  float	grid;
public:
  GridInfos(int mapW, int mapH);
 /* GridInfos(const GridInfos &);
  GridInfos	&operator=(const GridInfos &);*/
  ~GridInfos();

  int	getMapWidth() const;
  int	getMapHeigth() const;

  void	draw(int **map);// GridInfos *infos);
  void	drawLines(float valEnd, float valDraw, bool tf);
};

#endif