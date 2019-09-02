#pragma once
#include<SFML\Graphics.hpp>
#include"World.h"
class Game
{
	sf::RenderWindow mwindow;
	World			 mworld;
	sf::Time		 timePerFrame;


	void processEvents();
	void update(sf::Time deltaTime);
	void render();

public:
	Game();
	void run();
};

