#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "gameentity.h"
#include "resourceholder.h"

class GamePlayer : public GameEntity
{
public:
    explicit GamePlayer(const TextureHolder& textures, sf::RenderWindow& window);
    virtual void drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;

    void setMovingLeft();
    void setMovingRight();
    void setMovingUp();
    void setMovingDown();

    const int SPEED=200;

    virtual void updateCurrent(sf::Time dt);


private:
    sf::Sprite mSprite;
    sf::RenderWindow& mWindow;


    enum Direction {UP,DOWN,LEFT,RIGHT,STOP};
    Direction mDirection = STOP;

    const int FRAME_COUNT = 2;
    const int SPRITE_SIZE = 75;
    const int SPRITES_IN_TEXTURE = 5;

    int mCurrentFrame = 0;
    int mFrameCounter = 0;
    enum Mouth {OPENING,CLOSING};
    Mouth mAnimationDirection;

};

#endif // PLAYER_H
