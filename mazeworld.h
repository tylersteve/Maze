#ifndef MAZEWORLD_H
#define MAZEWORLD_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "scenenode.h"
#include "resourceholder.h"
#include <array>
#include "player.h"

class MazeWorld : private sf::NonCopyable
{
public:
    explicit MazeWorld(sf::RenderWindow& window, std::string basePath);
    void update(sf::Time dt);
    void draw();
    void handleInput(sf::Keyboard::Key keyCode);

private:
    void loadTextures();
    void buildScene();


    enum Layer {
        Maze,
        Goasts,
        Score,
        Player,
        LayerCount
    };

    std::string mBasePath;
    sf::RenderWindow& mWindow;
    SceneNode mSceneGraph;
    std::array<SceneNode*,Layer::LayerCount> mSceneLayers;
    TextureHolder mTextures;
    GamePlayer* mPlayer;
};

#endif // MAZEWORLD_H
