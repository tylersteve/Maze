#include "playerstate.h"
#include <iostream>

PlayerState::PlayerState() : mPlayerShape()
{
    loadGraphics();
    //mPlayerShape.setSize(sf::Vector2f(100,100));
    mPlayerShape.setPosition(100.0f,100.0f);
}

void PlayerState::move(sf::Time &deltaTime)
{
    sf::Vector2f moveVector (0.0f,0.0f);
    if (mMovingDown) {
        moveVector.y += mPlayerSpeed;
        mPlayerShape.setRotation(90);
        mDirection = DOWN;
    } else if (mMovingUp) {
        moveVector.y -= mPlayerSpeed;
        mDirection = UP;
        mPlayerShape.setRotation(-90);
    } else if (mMovingLeft) {
        moveVector.x -= mPlayerSpeed;
        mDirection = LEFT;
        mPlayerShape.setRotation(180);
    } else if (mMovingRight) {
        moveVector.x += mPlayerSpeed;
        mDirection = RIGHT;
        mPlayerShape.setRotation(0);
    }

    mPlayerShape.move(moveVector  * deltaTime.asSeconds());
}

void PlayerState::draw(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(mPlayerShape);
}

bool PlayerState::movingLeft() const
{
    return mMovingLeft;
}

void PlayerState::setMovingLeft(bool movingLeft)
{
    mMovingLeft = movingLeft;
}

bool PlayerState::movingRight() const
{
    return mMovingRight;
}

void PlayerState::setMovingRight(bool movingRight)
{
    mMovingRight = movingRight;
}

bool PlayerState::movingUp() const
{
    return mMovingUp;
}

void PlayerState::setMovingUp(bool movingUp)
{
    mMovingUp = movingUp;
}

bool PlayerState::movingDown() const
{
    return mMovingDown;
}

void PlayerState::setMovingDown(bool movingDown)
{
    mMovingDown = movingDown;
}

void PlayerState::loadGraphics()
{
    if (!mMainTexture.loadFromFile("graphics/player/Mouth.png")) {
        std::cout << "Error load image into texture";
    } else {
        std::cout << "Loaded image into texture" << std::endl;
        mPlayerShape.setTexture(mMainTexture);
        mPlayerShape.setOrigin(mMainTexture.getSize().x/2,mMainTexture.getSize().y/2);
    }
}


