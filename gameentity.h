#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <SFML/System/Vector2.hpp>
#include "scenenode.h"


class GameEntity : public SceneNode
{
public:
    GameEntity();
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity();

private:
    virtual void updateCurrent(sf::Time dt);
    sf::Vector2f mVelocity;
};

#endif // GAMEENTITY_H
