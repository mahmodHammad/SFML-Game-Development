#include "SpriteNode.h"

//i stoped here at 7::20 am
//i must fiz this shit to make background works



SpriteNode::SpriteNode(const sf::Texture & texture):mSprite(texture)
{
//std::cout << "settttted" << std::endl;

}

SpriteNode::SpriteNode(const sf::Texture & texture, const sf::IntRect & rect):mSprite(texture,rect)
{//	std::cout << "what the helllllll" << std::endl;
}

void SpriteNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
//	std::cout << "size.x"<<target.getSize().x<< std::endl;
}
