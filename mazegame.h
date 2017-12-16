#ifndef MAZEGAME_H
#define MAZEGAME_H

#include <SFML/Graphics.hpp>
#include "playerstate.h"

class MazeGame
{
public:
    MazeGame();
    ~MazeGame();
    void run();

private:
    void processEvents();
    void update(sf::Time &deltaTime);
    void render();
    void handleInput(sf::Keyboard::Key keyCode, bool pressed);

private:
    sf::RenderWindow mWindow;
    sf::RectangleShape mPlayerShape;
    sf::Time TimePerFrame = sf::seconds(1.0f / 60.0f);

    PlayerState *player1;
};

#endif // MAZEGAME_H
