#pragma once
#include<SFML\Graphics.hpp>
#include<memory>
#include<map>
#include<assert.h>
#include<iostream>
namespace Textures { enum ID { Eagle, Raptor, Desert }; };

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	/**
	@param  id --identifier to access or load my resource from mResourceMap
	@param 	filename -- path to my resource to load
	>load my resource as pointer from path to mResourceMap with ID as it's key
	*/
	void load(Identifier id,const std::string& filename);

	template<typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter &secondParam);

	/**
	@param  id --identifier to access my resource from mResourceMap
	>get my resource as pointer in mResourceMap 
	*/
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;
private:
	std::map<Identifier,std::unique_ptr<Resource>> mResourceMap;
};

#include"ResourceHandler.inl"



//a7aaa  what the hell <<i wanted my  templete at first to be defined before creation LOL !>>
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;