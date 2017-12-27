#include "mazegame.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

MazeGame::MazeGame(std::string basePath): mWindow(sf::VideoMode(1024,768),"Maze"),basePath(basePath),mMazeWorld(mWindow,basePath)
{
    mWindow.setVerticalSyncEnabled(true);
    mWindow.setMouseCursorVisible(false);
}

MazeGame::~MazeGame()
{
    //delete player1;
}

void MazeGame::run()
{
    sf::Clock clock;
    sf::Time timeSinceUpdate = sf::Time::Zero;

    while(mWindow.isOpen()) {
        timeSinceUpdate += clock.restart();

        while (timeSinceUpdate > TimePerFrame) {
            timeSinceUpdate -= TimePerFrame;
            processEvents();
            mMazeWorld.update(TimePerFrame);
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
                //handleInput(event.key.code,true);
                mMazeWorld.handleInput(event.key.code);
                break;

            case sf::Event::KeyReleased:
                //handleInput(event.key.code,false);
                mMazeWorld.handleInput(event.key.code);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
            default:
                break;
        }
    }
}


void MazeGame::render()
{
    mWindow.clear();
    mMazeWorld.draw();
    mWindow.display();
}


