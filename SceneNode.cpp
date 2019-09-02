#include "SceneNode.h"

SceneNode::SceneNode()
{
}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mchildren.push_back(std::move(child));
}

std::unique_ptr<SceneNode> SceneNode::detachChild(const SceneNode & node)
{
	//if found >>erase it from childrens
	auto found=std::find_if(mchildren.begin() ,mchildren.end() ,
		[&](Ptr & p) ->bool {return p.get() == &node;} //any waY
	);
	assert(found != mchildren.end());
	mchildren.erase(found);

	Ptr result = std::move(*found);
	//remove him from his parent
	result->mParent = nullptr;
	mchildren.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt)
{
	updateChildren(dt);
	updateCurrent(dt);
}
void SceneNode::updateCurrent(sf::Time dt)
{}

void SceneNode::updateChildren(sf::Time dt)
{
	for (Ptr& child : mchildren)
		child->update(dt);
}

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	/*operator*= combines the parent's
absolute transform with the current node's relative one. The result is the absolute
transform of the current node, which stores where in the world our scene node
is placed.*/
	states.transform *= getTransform();
	//Now, states.transform contains the absolute world transform.
	drawCurrent(target, states);
	for (const Ptr& child : mchildren)
		child->draw(target,states);
}

void SceneNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{}
