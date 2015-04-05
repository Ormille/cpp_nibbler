//
// sfml.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:03 2015 Julie Terranova
// Last update Sun Apr  5 15:06:58 2015 terran_j
//

#include <iostream>
#include "sfml.hh"

SFML::SFML()
{
  this->buildMaps();
}

SFML::~SFML()
{}

int	SFML::initLib(unsigned int x, unsigned int y)
{
  sf::RenderWindow *n;
  sf::Font *font = new sf::Font();

  if (x * 35 > 1800 || y * 35 > 1000)
    this->_size = 15;
  else
    this->_size = 35;

  if (x * this->_size > 1800 || y * this->_size > 1000)
    {
      std::cerr << "Too hight parameters, try again." << std::endl;
      return (-1);
    }

  n = new sf::RenderWindow(sf::VideoMode((2 + x) * this->_size, (2 + y) * this->_size),
			   "Nibbler SFML",
			   sf::Style::Titlebar | sf::Style::Close);

  if (!this->_music.openFromFile("SFML/textures/music.ogg"))
    return (-1);
  this->_music.play();
  this->_window = n;
  this->_x = x;
  this->_y = y;

  sf::Texture *texture2 = new sf::Texture();
  texture2->loadFromFile("SFML/textures/bords.png");
  sf::Sprite bords(*texture2);
  this->_bords = bords;

  sf::Texture *texture3 = new sf::Texture();
  texture3->loadFromFile("SFML/textures/snake.png");
  sf::Sprite snake(*texture3);
  this->_snake = snake;

  sf::Texture *texture4 = new sf::Texture();
  texture4->loadFromFile("SFML/textures/tete.png");
  sf::Sprite tete(*texture4);
  this->_tete = tete;

  sf::Texture *texture5 = new sf::Texture();
  texture5->loadFromFile("SFML/textures/queue.png");
  sf::Sprite queue(*texture5);
  this->_queue = queue;

  sf::Texture *texture6 = new sf::Texture();
  texture6->loadFromFile("SFML/textures/fruit1.png");
  sf::Sprite fruit1(*texture6);
  this->_fruit1 = fruit1;

  sf::Texture *texture7 = new sf::Texture();
  texture7->loadFromFile("SFML/textures/fruit2.png");
  sf::Sprite fruit2(*texture7);
  this->_fruit2 = fruit2;

  sf::Texture *texture8 = new sf::Texture();
  texture8->loadFromFile("SFML/textures/fruit3.png");
  sf::Sprite fruit3(*texture8);
  this->_fruit3 = fruit3;

  sf::Texture *texture9 = new sf::Texture();
  texture9->loadFromFile("SFML/textures/fruit4.png");
  sf::Sprite fruit4(*texture9);
  this->_fruit4 = fruit4;

  sf::Texture *texture10 = new sf::Texture();
  texture10->loadFromFile("SFML/textures/fruit5.png");
  sf::Sprite fruit5(*texture10);
  this->_fruit5 = fruit5;

  sf::Texture *texture11 = new sf::Texture();
  texture11->loadFromFile("SFML/textures/fruit6.png");
  sf::Sprite fruit6(*texture11);
  this->_fruit6 = fruit6;

  sf::Texture *texture12 = new sf::Texture();
  texture12->loadFromFile("SFML/textures/fruit7.png");
  sf::Sprite fruit7(*texture12);
  this->_fruit7 = fruit7;

  sf::Texture *texture13 = new sf::Texture();
  texture13->loadFromFile("SFML/textures/fruit8.png");
  sf::Sprite fruit8(*texture13);
  this->_fruit8 = fruit8;

  sf::Texture *texture14 = new sf::Texture();
  texture14->loadFromFile("SFML/textures/swimm.png");
  sf::Sprite swimm(*texture14);
  this->_swimm = swimm;

  sf::Texture *texture15 = new sf::Texture();
  texture15->loadFromFile("SFML/textures/portal.png");
  sf::Sprite portal(*texture15);
  this->_portal = portal;

  if (!font->loadFromFile("SFML/textures/arial.ttf"))
    return (-1);
  this->_txt.setFont(*font);

  return (0);
}

int	SFML::getEvent()
{
  sf::Event Event;

  while (this->_window->pollEvent(Event))
    {
      if (Event.type == sf::Event::Closed)
	return (27);
      else if (Event.type == sf::Event::KeyPressed)
	{
	  if (this->_mape.find(Event.key.code) != this->_mape.end())
	    return this->_mape[Event.key.code];
	  else
	    return Event.key.code;
	}
    }
  return (-1);
}

void	SFML::refreshImg(int **map)
{
  int x = 0;
  int y;

  this->_window->clear(sf::Color::Black);
  ++this->_span;
  while (x < this->_x + 2)
    {
      y = 0;
      while (y < this->_y + 2)
	{
	  if (this->_mapf.find(map[x][y]) != this->_mapf.end())
	    (this->* (this->_mapf[map[x][y]]))(x, y);
	  y++;
	}
      x++;
    }
  if (this->_span < 75)
    this->_window->draw(this->_txt);
  this->_window->display();
}

void SFML::buildMaps()
{
  this->_mapf[2147483647] = &SFML::fbords;
  this->_mapf[1] = &SFML::ftete;
  this->_mapf[2] = &SFML::fsnake;
  this->_mapf[3] = &SFML::fqueue;
  this->_mapf[10] = &SFML::fswimm;
  this->_mapf[-100] = &SFML::fportal;
  this->_mapf[-1] = &SFML::ffruit1;
  this->_mapf[-2] = &SFML::ffruit2;
  this->_mapf[-3] = &SFML::ffruit3;
  this->_mapf[-4] = &SFML::ffruit4;
  this->_mapf[-5] = &SFML::ffruit5;
  this->_mapf[-6] = &SFML::ffruit6;
  this->_mapf[-7] = &SFML::ffruit7;
  this->_mapf[-8] = &SFML::ffruit8;
  this->_mape[71] = 276;
  this->_mape[72] = 275;
  this->_mape[73] = 273;
  this->_mape[74] = 274;
  this->_mape[36] = 27;
  this->_mape[57] = 32;
  this->_mape[59] = 8;
}

void SFML::fbords(int x, int y)
{
  this->_bords.setPosition(x * this->_size, y * this->_size);
  this->_bords.setScale(1.0f, 1.0f);
  this->_bords.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_bords);
}

void SFML::ftete(int x, int y)
{
  this->_tete.setPosition(x * this->_size, y * this->_size);
  this->_tete.setScale(1.0f, 1.0f);
  this->_tete.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_tete);
}

void SFML::fsnake(int x, int y)
{
  this->_snake.setPosition(x * this->_size, y * this->_size);
  this->_snake.setScale(1.0f, 1.0f);
  this->_snake.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_snake);
}

void SFML::fqueue(int x, int y)
{
  this->_queue.setPosition(x * this->_size, y * this->_size);
  this->_queue.setScale(1.0f, 1.0f);
  this->_queue.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_queue);
}

void SFML::fswimm(int x, int y)
{
  this->_swimm.setPosition(x * this->_size, y * this->_size);
  this->_swimm.setScale(1.0f, 1.0f);
  this->_swimm.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_swimm);
}

void SFML::fportal(int x, int y)
{
  this->_portal.setPosition(x * this->_size, y * this->_size);
  this->_portal.setScale(1.0f, 1.0f);
  this->_portal.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_portal);
}

void SFML::ffruit1(int x, int y)
{
  this->_fruit1.setPosition(x * this->_size, y * this->_size);
  this->_fruit1.setScale(1.0f, 1.0f);
  this->_fruit1.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_fruit1);
}

void SFML::ffruit2(int x, int y)
{
  this->_fruit2.setPosition(x * this->_size, y * this->_size);
  this->_fruit2.setScale(1.0f, 1.0f);
  this->_fruit2.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_fruit2);
}

void SFML::ffruit3(int x, int y)
{
  this->_fruit3.setPosition(x * this->_size, y * this->_size);
  this->_fruit3.setScale(1.0f, 1.0f);
  this->_fruit3.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_fruit3);
}

void SFML::ffruit4(int x, int y)
{
  this->_fruit4.setPosition(x * this->_size, y * this->_size);
  this->_fruit4.setScale(1.0f, 1.0f);
  this->_fruit4.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_fruit4);
}

void SFML::ffruit5(int x, int y)
{
  this->_fruit5.setPosition(x * this->_size, y * this->_size);
  this->_fruit5.setScale(1.0f, 1.0f);
  this->_fruit5.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_fruit5);
}

void SFML::ffruit6(int x, int y)
{
  this->_fruit6.setPosition(x * this->_size, y * this->_size);
  this->_fruit6.setScale(1.0f, 1.0f);
  this->_fruit6.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_fruit6);
}

void SFML::ffruit7(int x, int y)
{
  this->_fruit7.setPosition(x * this->_size, y * this->_size);
  this->_fruit7.setScale(1.0f, 1.0f);
  this->_fruit7.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_fruit7);
}

void SFML::ffruit8(int x, int y)
{
  this->_fruit8.setPosition(x * this->_size, y * this->_size);
  this->_fruit8.setScale(1.0f, 1.0f);
  this->_fruit8.scale(1.0f * this->_size / 95, 1.0f * this->_size / 95);
  this->_window->draw(this->_fruit8);
}

void	SFML::affText(const std::string &toAff)
{
  this->_txt.setString(toAff);
  this->_txt.setCharacterSize(24);
  this->_txt.setColor(sf::Color::White);
  this->_txt.setPosition(this->_x * this->_size / 3, this->_y * this->_size / 4);
  this->_span = 0;
}

void    SFML::closeLib()
{
  this->_music.stop();

  this->_txt.setString("Game Over");
  this->_txt.setCharacterSize(54);
  this->_txt.setColor(sf::Color::White);
  this->_txt.setPosition(this->_x * this->_size / 3, this->_y * this->_size / 2);
  this->_window->draw(this->_txt);
  this->_window->display();
  sleep(1.5);
  this->_window->close();
}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "SFML loaded."<< std::endl;
  return (new SFML());
}
