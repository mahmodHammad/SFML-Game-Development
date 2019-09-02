#include "Game.h"


Game::Game():mwindow(sf::VideoMode(640,800) ,"coky poky"),mworld(mwindow)
{
	mIsMovingUp    =false;
	mIsMovingDown  =false;
	mIsMovingLeft  =false;
	mIsMovingRight =false;
	timePerFrame = sf::seconds(1.f / 60.f);
}

void Game::processEvents()
{
	sf::Event event;
	while (mwindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mwindow.close();
			break;
		
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		default:
			break;
		}
		if (event.type == sf::Event::Closed)
			mwindow.close();
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= 1.f;
	if (mIsMovingDown)
		movement.y += 1.f;
	if (mIsMovingLeft)
		movement.x -= 1.f; 
	if (mIsMovingRight)
		movement.x += 1.f;

	mworld.update(deltaTime);
}

void Game::render()
{
	mwindow.clear();

	mworld.draw();
//	mwindow.setView(mwindow.getDefaultView());
	mwindow.display();
}


void Game::run()
{
	sf::Clock clock;
	sf::Time TimeSinceLastUpdate = sf::Time::Zero;

	while (mwindow.isOpen()) {
		processEvents();
		TimeSinceLastUpdate += clock.restart();
		while (TimeSinceLastUpdate>timePerFrame)
		{
			TimeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

