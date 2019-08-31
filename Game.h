#pragma once
#include<SFML\Graphics.hpp>
#include"World.h"
class Game
{
	// ResourceHolder <sf::Texture,Textures::ID> resource;


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
	
	
	World mworld;
public:
	Game();
	void run();
};

