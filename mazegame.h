#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <SFML/Graphics.hpp>
#include "playerstate.h"
#include "resourceholder.h"
#include "mazeworld.h"

class MazeGame
{
public:
    MazeGame(std::string basePath);
    ~MazeGame();
    void run();

private:
    void processEvents();
    void update(sf::Time &deltaTime);
    void render();
    void handleInput(sf::Keyboard::Key keyCode, bool pressed);

private:
    sf::RenderWindow mWindow;
    std::string basePath;

    sf::RectangleShape mPlayerShape;
    sf::Time TimePerFrame = sf::seconds(1.0f / 60.0f);

    MazeWorld mMazeWorld;
   // PlayerState *player1;
    ResourceHolder<sf::Texture,int> mTextures;
};

#endif // MAZEGAME_H
