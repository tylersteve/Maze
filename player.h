#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "gameentity.h"
#include "resourceholder.h"

class GamePlayer : public GameEntity
{
public:
    explicit GamePlayer(const TextureHolder& textures);
    virtual void drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;

    void move(sf::Time &deltaTime);

    void setMovingLeft();
    void setMovingRight();
    void setMovingUp();
    void setMovingDown();

private:
    sf::Sprite mSprite;

    enum Direction {UP,DOWN,LEFT,RIGHT,STOP};
    Direction mDirection = STOP;
};

#endif // PLAYER_H
