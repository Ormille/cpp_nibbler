//
// sfml.cpp for nibbler in /home/terran_j/rendu/cpp_nibbler
//
// Made by Julie Terranova
// Login   <terran_j@epitech.net>
//
// Started on  Tue Mar 24 17:01:03 2015 Julie Terranova
// Last update Sat Apr  4 19:04:16 2015 terran_j
//

#include <iostream>
#include "sfml.hh"

SFML::SFML()
{}

SFML::~SFML()
{}

int	SFML::initLib(unsigned int x, unsigned int y)
{
  sf::RenderWindow *n;

  if (x * SIZE > 1800 || y * SIZE > 1000)
    {
      std::cerr << "Too hight parameters, try again." << std::endl;
      return (-1);
    }

  n = new sf::RenderWindow(sf::VideoMode((2 + x) * SIZE, (2 + y) * SIZE),
			   "Nibbler SFML",
			   sf::Style::Titlebar | sf::Style::Close);

  if (!this->_music.openFromFile("SFML/textures/music.ogg"))
    return (-1);
  this->_music.play();

  this->_window = n;
  this->_x = x;
  this->_y = y;

  sf::Texture *texture1 = new sf::Texture();
  if (!texture1->loadFromFile("SFML/textures/background.png"))
    return (-1);
  sf::Sprite background(*texture1);
  this->_background = background;

  sf::Texture *texture2 = new sf::Texture();
  if (!texture2->loadFromFile("SFML/textures/bords.png"))
    return (-1);
  sf::Sprite bords(*texture2);
  this->_bords = bords;

  sf::Texture *texture3 = new sf::Texture();
  if (!texture3->loadFromFile("SFML/textures/snake.png"))
    return (-1);
  sf::Sprite snake(*texture3);
  this->_snake = snake;

  sf::Texture *texture4 = new sf::Texture();
  if (!texture4->loadFromFile("SFML/textures/tete.png"))
    return (-1);
  sf::Sprite tete(*texture4);
  this->_tete = tete;

  sf::Texture *texture5 = new sf::Texture();
  if (!texture5->loadFromFile("SFML/textures/queue.png"))
    return (-1);
  sf::Sprite queue(*texture5);
  this->_queue = queue;

  sf::Texture *texture6 = new sf::Texture();
  if (!texture6->loadFromFile("SFML/textures/fruit1.png"))
    return (-1);
  sf::Sprite fruit1(*texture6);
  this->_fruit1 = fruit1;

  sf::Texture *texture7 = new sf::Texture();
  if (!texture7->loadFromFile("SFML/textures/fruit2.png"))
    return (-1);
  sf::Sprite fruit2(*texture7);
  this->_fruit2 = fruit2;

  sf::Texture *texture8 = new sf::Texture();
  if (!texture8->loadFromFile("SFML/textures/fruit3.png"))
    return (-1);
  sf::Sprite fruit3(*texture8);
  this->_fruit3 = fruit3;

  sf::Texture *texture9 = new sf::Texture();
  if (!texture9->loadFromFile("SFML/textures/fruit4.png"))
    return (-1);
  sf::Sprite fruit4(*texture9);
  this->_fruit4 = fruit4;

  sf::Texture *texture10 = new sf::Texture();
  if (!texture10->loadFromFile("SFML/textures/fruit5.png"))
    return (-1);
  sf::Sprite fruit5(*texture10);
  this->_fruit5 = fruit5;

  sf::Texture *texture11 = new sf::Texture();
  if (!texture11->loadFromFile("SFML/textures/fruit6.png"))
    return (-1);
  sf::Sprite fruit6(*texture11);
  this->_fruit6 = fruit6;

  sf::Texture *texture12 = new sf::Texture();
  if (!texture12->loadFromFile("SFML/textures/fruit7.png"))
    return (-1);
  sf::Sprite fruit7(*texture12);
  this->_fruit7 = fruit7;

  sf::Texture *texture13 = new sf::Texture();
  if (!texture13->loadFromFile("SFML/textures/fruit8.png"))
    return (-1);
  sf::Sprite fruit8(*texture13);
  this->_fruit8 = fruit8;

  sf::Texture *texture14 = new sf::Texture();
  if (!texture14->loadFromFile("SFML/textures/swimm.png"))
    return (-1);
  sf::Sprite swimm(*texture14);
  this->_swimm = swimm;

  sf::Texture *texture15 = new sf::Texture();
  if (!texture15->loadFromFile("SFML/textures/portal.png"))
    return (-1);
  sf::Sprite portal(*texture15);
  this->_portal = portal;

  return (0);
}

int	SFML::getEvent()
{
  sf::Event Event;

  while (this->_window->pollEvent(Event))
    {
      if (Event.type == sf::Event::Closed)
	return (27);
      else if (Event.type == sf::Event::KeyPressed) // -42 si je change pas ca, faire map
	{
	  if (Event.key.code == 71)
	    return (276); // gauche
	  else if (Event.key.code == 72)
	    return (275); // droite
	  else if (Event.key.code == 73)
	    return (273); // haut
	  else if (Event.key.code == 74)
	    return (274); // bas
	  else if (Event.key.code == 36)
	    return (27); // echap
	  else if (Event.key.code == 57)
	    return (32); // space
	  else if (Event.key.code == 59)
	    return (8); // del
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

  this->_background.setPosition(0, 0);
  this->_window->draw(this->_background);

  while (x < this->_x + 2)
    {
      y = 0;
      while (y < this->_y + 2)
	{
	  if (map[x][y] == 2147483647)
	    {
	      this->_bords.setPosition(x * SIZE, y * SIZE);
	      this->_bords.setScale(1.0f, 1.0f);
	      this->_bords.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_bords);
	    }
	  if (map[x][y] == 1)
	    {
	      this->_tete.setPosition(x * SIZE, y * SIZE);
	      this->_tete.setScale(1.0f, 1.0f);
	      this->_tete.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_tete);
	    }
	  if (map[x][y] == 2)
	    {
	      this->_snake.setPosition(x * SIZE, y * SIZE);
	      this->_snake.setScale(1.0f, 1.0f);
	      this->_snake.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_snake);
	    }
	  if (map[x][y] == 3)
	    {
	      this->_queue.setPosition(x * SIZE, y * SIZE);
	      this->_queue.setScale(1.0f, 1.0f);
	      this->_queue.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_queue);
	    }
	  if (map[x][y] == -1)
	    {
	      this->_fruit1.setPosition(x * SIZE, y * SIZE);
	      this->_fruit1.setScale(1.0f, 1.0f);
	      this->_fruit1.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_fruit1);
	    }
	  if (map[x][y] == -2)
	    {
	      this->_fruit2.setPosition(x * SIZE, y * SIZE);
	      this->_fruit2.setScale(1.0f, 1.0f);
	      this->_fruit2.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_fruit2);
	    }
	  if (map[x][y] == -3)
	    {
	      this->_fruit3.setPosition(x * SIZE, y * SIZE);
	      this->_fruit3.setScale(1.0f, 1.0f);
	      this->_fruit3.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_fruit3);
	    }
	  if (map[x][y] == -4)
	    {
	      this->_fruit4.setPosition(x * SIZE, y * SIZE);
	      this->_fruit4.setScale(1.0f, 1.0f);
	      this->_fruit4.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_fruit4);
	    }
	  if (map[x][y] == -5)
	    {
	      this->_fruit5.setPosition(x * SIZE, y * SIZE);
	      this->_fruit5.setScale(1.0f, 1.0f);
	      this->_fruit5.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_fruit5);
	    }
	  if (map[x][y] == -6)
	    {
	      this->_fruit6.setPosition(x * SIZE, y * SIZE);
	      this->_fruit6.setScale(1.0f, 1.0f);
	      this->_fruit6.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_fruit6);
	    }
	  if (map[x][y] == -7)
	    {
	      this->_fruit7.setPosition(x * SIZE, y * SIZE);
	      this->_fruit7.setScale(1.0f, 1.0f);
	      this->_fruit7.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_fruit7);
	    }
	  if (map[x][y] == -8)
	    {
	      this->_fruit8.setPosition(x * SIZE, y * SIZE);
	      this->_fruit8.setScale(1.0f, 1.0f);
	      this->_fruit8.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_fruit8);
	    }
	  if (map[x][y] == 10)
	    {
	      this->_swimm.setPosition(x * SIZE, y * SIZE);
	      this->_swimm.setScale(1.0f, 1.0f);
	      this->_swimm.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_swimm);
	    }
	  if (map[x][y] == -100)
	    {
	      this->_portal.setPosition(x * SIZE, y * SIZE);
	      this->_portal.setScale(1.0f, 1.0f);
	      this->_portal.scale(1.0f * SIZE / 95, 1.0f * SIZE / 95);
	      this->_window->draw(this->_portal);
	    }

	  y++;
	}
      x++;
    }

  this->_window->display();
}

void	SFML::affText(const std::string &toAff)
{
  std::cout << toAff << std::endl; // atej
}

void    SFML::closeLib()
{
  this->_window->close();
  // clean textures en mémoire:
  //  delete(this->_background);

  this->_music.stop();
}

extern "C"
IObjGraph *nibbler_entry_point()
{
  std::cout << "SFML loaded."<< std::endl;
  return (new SFML());
}
