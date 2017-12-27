#include "player.h"

GamePlayer::GamePlayer(const TextureHolder& textures) : mSprite(textures.get(Textures::Player))
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width /2, bounds.height/2);
}

void GamePlayer::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mSprite,states);
}


void GamePlayer::move(sf::Time &deltaTime)
{
    sf::Vector2f moveVector (0.0f,0.0f);

    switch(mDirection)
    {
    case DOWN:
        moveVector.y += getVelocity().y;
        mSprite.setRotation(90);
        mDirection = DOWN;
        break;

    case UP:
        moveVector.y -= getVelocity().y;
        mDirection = UP;
        mSprite.setRotation(-90);
        break;

    case LEFT:
        moveVector.x -= getVelocity().x;
        mDirection = LEFT;
        mSprite.setRotation(180);
        break;

    case RIGHT:
        moveVector.x += getVelocity().x;
        mDirection = RIGHT;
        mSprite.setRotation(0);
        break;
    }

    mSprite.move(moveVector  * deltaTime.asSeconds());
}


void GamePlayer::setMovingLeft()
{
    mDirection = LEFT;
}


void GamePlayer::setMovingRight()
{
    mDirection = RIGHT;
}


void GamePlayer::setMovingUp()
{
    mDirection = UP;
}


void GamePlayer::setMovingDown()
{
    mDirection = DOWN;
}
