#pragma once
#include<SFML\Graphics.hpp>
#include"SceneNode.h"
class Entity :public SceneNode //i am not sure
{
private:
	sf::Vector2f mVelocity;
public:
	Entity();

	void setVelocity(sf::Vector2f v);
	void setVelocity(float vx,float vy);
	sf::Vector2f getmVelocity();

	virtual void updateCurrent(sf::Time dt);



};

