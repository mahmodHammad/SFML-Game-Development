#pragma once
#include<SFML\Graphics.hpp>
#include"ResourceHandler.h"
#include<memory>
#include<vector>
#include<assert.h>
class SceneNode:public sf::Transformable
	,public sf::Drawable ,private sf::NonCopyable
{
private:
	typedef std::unique_ptr<SceneNode> Ptr;
	std::vector<Ptr> mchildren;
	SceneNode*		 mParent;

public:
	SceneNode();

	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);
	
	void update(sf::Time dt);

private:
	/*
	it has to deal with different transforms:
	get current node transform(position , rotaion)
	realtivee to the parent ..from sf::Transformable::getTransform();

	hold the passed transform ,,from strate witch 
	has member variable transform of type sf::transform
	*/
	virtual void draw(sf::RenderTarget&target, 
		sf::RenderStates states)const;

	//draw only the current not child
	virtual void drawCurrent(sf::RenderTarget&target,
		sf::RenderStates states) const;


	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);

	sf::Transform getWorldTransform();//const
	sf::Vector2f  getWorldPosition();//const
};
