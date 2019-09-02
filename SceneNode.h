#pragma once
#include<SFML\Graphics.hpp>
#include"ResourceHandler.h"
#include<memory>
#include<vector>
#include<assert.h>
class SceneNode:public sf::Transformable
	,public sf::Drawable ,private sf::NonCopyable
{

public:
	typedef std::unique_ptr<SceneNode> Ptr;
	SceneNode();

	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
	
	void update(sf::Time dt);

private:
	std::vector<Ptr> mchildren;
	SceneNode*		 mParent;
private:
	/*
	it has to deal with different transforms:
	get current node transform(position , rotaion)
	realtivee to the parent ..from sf::Transformable::getTransform();

	hold the passed transform ,,from strate witch 
	has member variable transform of type sf::transform
	*/
	virtual void draw(sf::RenderTarget&target, sf::RenderStates states)const;

	//draw only the current not child
	virtual void drawCurrent(sf::RenderTarget&target,sf::RenderStates states) const;


	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);

};
