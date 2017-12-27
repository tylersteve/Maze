#include "mazegame.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

MazeGame::MazeGame(std::string basePath): mWindow(sf::VideoMode(1024, 768),"Maze",sf::Style::None),basePath(basePath),mMazeWorld(mWindow,basePath)
{
    mWindow.setVerticalSyncEnabled(true);
    mWindow.setMouseCursorVisible(false);
}

MazeGame::~MazeGame()
{
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
                mMazeWorld.handleInput(event.key.code);
                break;

            case sf::Event::KeyReleased:
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


