#pragma once
#include"Aircraft.h"
#include"SpriteNode.h"
#include<array>

/*
----we need all the date ralated to rendering ----

>>a refrendce to render window
>>world's current view
>>texture Holder with all textures needed inside the world
>>the scene graph
>>some pointers to access the scene graph's layer nodes


----we store some logical data----

>> the bounding  of world
>> initial player's position
>> scrolling speed
>> pointer to player aircraft


--we impement public functions <<update  ,  render>>
--we impement private functions <<load the texture,  to build up the scene>>


*/
class World:private sf::NonCopyable
{

private:
	sf::RenderWindow&					mWindow;
	enum Layer{	Background, Air, LayerCount	};
	sf::View							mWorldView;
	TextureHolder						mTextures;
	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>  mSceneLayers;
	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	float								mScrollSpeed;
	Aircraft*							mPlayerAircraft;



private:
	void loadTextures();
	void buildScene();




public:
	World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();
};

