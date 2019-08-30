#pragma once
#include "SceneNode.h"
class SpriteNode :	public SceneNode
{
private:
	sf::Sprite mSprite;
	virtual void drawCurrent(sf::RenderTarget&target
		,sf::RenderStates states) const;
public:
	SpriteNode(const sf::Texture &texture);
	SpriteNode(const sf::Texture &texture , const sf::IntRect &rect);

};

