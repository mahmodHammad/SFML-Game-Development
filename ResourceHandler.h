#pragma once
#include<SFML\Graphics.hpp>
#include<memory>
#include<map>
#include<assert.h>
#include<iostream>
namespace Textures {enum ID{ Eagle, Raptor};}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void load(Identifier id,	const std::string& filename);

	template<typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter &secondParam);

	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;
private:
	std::map<Identifier,std::unique_ptr<Resource>> mResourceMap;
};

#include"ResourceHandler.inl"
