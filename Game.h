#pragma once
#include<SFML\Graphics.hpp>
#include"ResourceHandler.h"
class Game
{
	ResourceHandler resource;
	sf::RenderWindow mwindow;
	sf::Texture mtexture;
	sf::Sprite mplayer;

	float speed;

	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
	sf::Time timePerFrame;

	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	void handlePlayerInput(sf::Keyboard::Key key ,bool isPressed);
public:
	Game();
	void run();
};

