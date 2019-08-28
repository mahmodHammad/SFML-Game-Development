#pragma once
#include<SFML\Graphics.hpp>
#include<memory>
#include<map>
namespace Textures {enum ID{landscape ,Airplane,Missle};}

class ResourceHandler
{
private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>>mTextureMap;

public:
	ResourceHandler();
	~ResourceHandler();
	void load(Textures::ID id, const std::string&filename);
	sf::Texture & get(Textures::ID id);
	const sf::Texture & get(Textures::ID id) const;
};

