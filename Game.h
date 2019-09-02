#pragma once
#include<SFML\Graphics.hpp>
#include"World.h"
class Game
{
	sf::RenderWindow mwindow;
	World			 mworld;

	bool			 mIsMovingUp;
	bool			 mIsMovingDown;
	bool			 mIsMovingLeft;
	bool			 mIsMovingRight;
	sf::Time		 timePerFrame;


	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handlePlayerInput(sf::Keyboard::Key key ,bool isPressed);

public:
	Game();
	void run();
};

