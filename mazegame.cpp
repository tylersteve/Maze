#include "mazegame.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

MazeGame::MazeGame(std::string basePath): mWindow(sf::VideoMode(1024,768),"Maze"),basePath(basePath)
{
    mWindow.setVerticalSyncEnabled(true);
    mWindow.setMouseCursorVisible(false);


    std::cout << "this->basePath=" << this->basePath << std::endl;
    mTextures.loadResource(0,basePath.append("/graphics/player/Mouth.png"));
}

MazeGame::~MazeGame()
{
    //delete player1;
}

void MazeGame::run()
{
    player1 = new PlayerState(mTextures);
    sf::Clock clock;
    sf::Time timeSinceUpdate = sf::Time::Zero;

    while(mWindow.isOpen()) {
        processEvents();
        timeSinceUpdate += clock.restart();

        while (timeSinceUpdate > TimePerFrame) {
            timeSinceUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void MazeGame::processEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handleInput(event.key.code,true);
                break;

            case sf::Event::KeyReleased:
                handleInput(event.key.code,false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}

void MazeGame::update(sf::Time &deltaTime)
{
    player1->move(deltaTime);
}

void MazeGame::render()
{
    mWindow.clear();
    //mWindow.draw(mPlayerShape);
    player1->draw(mWindow);
    mWindow.display();
}

void MazeGame::handleInput(sf::Keyboard::Key keyCode, bool pressed)
{
    switch (keyCode) {
    case sf::Keyboard::Up:
        player1->setMovingUp(pressed);
        break;
    case sf::Keyboard::Down:
        player1->setMovingDown(pressed);
        break;
    case sf::Keyboard::Left:
        player1->setMovingLeft(pressed);
        break;
    case sf::Keyboard::Right:
        player1->setMovingRight(pressed);
        break;
    case sf::Keyboard::Q:
        mWindow.close();
    default:
        break;
    }
}
