#include "gameentity.h"

GameEntity::GameEntity()
{

}

void GameEntity::setVelocity(sf::Vector2f velocity)
{
    mVelocity = velocity;
}

void GameEntity::setVelocity(float vx, float vy)
{
    mVelocity.x = vx;
    mVelocity.y = vy;
}

sf::Vector2f GameEntity::getVelocity()
{
    return mVelocity;
}

void GameEntity::updateCurrent(sf::Time dt)
{
    move(mVelocity * dt.asSeconds());
}
