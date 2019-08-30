#include "Aircraft.h"

Textures::ID toTextureId(Aircraft::Type type)
{
	switch (type)
	{
	case Aircraft::Eagle:
		return Textures::Eagle;
		//break;
	case Aircraft::Raptor:
		return Textures::Raptor;
	//	break;
	}
}


Aircraft::Aircraft(Type type, const TextureHolder & textures):
	mType(type),msprite(textures.get(toTextureId(type))) //may be a bug in textures
{
	sf::FloatRect bounds = msprite.getLocalBounds();
	msprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(msprite ,states);
}

