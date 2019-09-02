#include "Game.h"


Game::Game():mwindow(sf::VideoMode(640,800) ,"coky poky"),mworld(mwindow)
{
	
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
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	mworld.update(deltaTime);
}

void Game::render()
{
	mwindow.clear();
	mworld.draw();
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

