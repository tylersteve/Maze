#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class PlayerState
{
public:
    PlayerState();

    void move(sf::Time &deltaTime);
    void draw(sf::RenderWindow &renderWindow);

    bool movingLeft() const;
    void setMovingLeft(bool movingLeft);

    bool movingRight() const;
    void setMovingRight(bool movingRight);

    bool movingUp() const;
    void setMovingUp(bool movingUp);

    bool movingDown() const;
    void setMovingDown(bool movingDown);


private:
    bool mMovingLeft;
    bool mMovingRight;
    bool mMovingUp;
    bool mMovingDown;
    enum Direction {UP,DOWN,LEFT,RIGHT};
    Direction mDirection = RIGHT;

    sf::Vector2f mPosition;
    float mPlayerSpeed = 100.0f;
    sf::Sprite mPlayerShape;

    sf::Texture mMainTexture;

    void loadGraphics();
};

#endif // PLAYERSTATE_H
