#include "Entity.h"

Entity::Entity()
{
}

void Entity::setVelocity(sf::Vector2f v)
{
	mVelocity = v;
}
void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}
sf::Vector2f Entity::getmVelocity()
{
	return this->mVelocity;
}

void Entity::updateCurrent(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}
