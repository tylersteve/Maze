#include "mazeworld.h"
#include "scenenode.h"

MazeWorld::MazeWorld(sf::RenderWindow &window, std::string basePath) : mBasePath(basePath),mWindow(window)
{
    loadTextures();
    buildScene();
}

void MazeWorld::update(sf::Time dt)
{
    mSceneGraph.update(dt);
}

void MazeWorld::draw()
{
    mWindow.draw(mSceneGraph);
}

void MazeWorld::loadTextures()
{
    mTextures.loadResource(Textures::Player,mBasePath.append("/graphics/player/MouthSprites_75x75.png"));
}

void MazeWorld::buildScene()
{
    // Create the layers and add them to the scene graph
    for (std::size_t i=0;i < Layer::LayerCount;i++) {
        SceneNode::SceneNodePtr layer(new SceneNode());
        mSceneLayers[i] = layer.get();
        mSceneGraph.attachChild(std::move(layer));
    }

    // Add the player to the player layer
    std::unique_ptr<GamePlayer> player1(new GamePlayer(mTextures,mWindow));
    mPlayer = player1.get();
    mSceneLayers[Layer::Player]->attachChild(std::move(player1));
    mPlayer->setPosition(200,200);
    mPlayer->setVelocity(0,0);
}

void MazeWorld::handleInput(sf::Keyboard::Key keyCode)
{
    switch (keyCode) {
    case sf::Keyboard::Up:
        mPlayer->setMovingUp();
        break;
    case sf::Keyboard::Down:
        mPlayer->setMovingDown();
        break;
    case sf::Keyboard::Left:
        mPlayer->setMovingLeft();
        break;
    case sf::Keyboard::Right:
        mPlayer->setMovingRight();
        break;
    case sf::Keyboard::Q:
        mWindow.close();
    default:
        break;
    }
}
