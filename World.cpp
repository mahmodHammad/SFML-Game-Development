#include "World.h"


World::World(sf::RenderWindow & window):mWindow(window)
,mWorldView(window.getDefaultView())
,mWorldBounds(0.f,0.f,mWorldView.getSize().x,100100)
,mSpawnPosition(mWorldView.getSize().x/2.f ,
	mWorldBounds.height - mWorldView.getSize().x) //not sure
,mPlayerAircraft(nullptr)

{
	mScrollSpeed = -1115;//habda

	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition); //center view with player
}


void World::loadTextures()
{
	mTextures.load(Textures::Eagle,   "resources/Textures/Eagle.png");
	mTextures.load(Textures::Raptor, "resources/Textures/Raptor.png");
	mTextures.load(Textures::Desert,"resources/Textures/Desert.png");
}

void World::buildScene() //dont know
{
	for (size_t i = 0; i < LayerCount; ++i)
	{
		//initialize the different scene layers 
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		//we attach each layer to our root scene node
		mSceneGraph.attachChild(std::move(layer));
	}

	//configure background to repeat itself
	sf::Texture & texture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);


	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left,mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));


	std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures));
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity(0, mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(leader));


	std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Raptor, mTextures));
	leftEscort->setPosition(-80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(leftEscort));

}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt)
{
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getmVelocity();
	mPlayerAircraft->setVelocity(velocity);
	mSceneGraph.update(dt);
}