#include "player.h"


GamePlayer::GamePlayer(const TextureHolder& textures, sf::RenderWindow &window) : mSprite(textures.get(Textures::Player)),mWindow(window)
{
    //sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(SPRITE_SIZE /2, SPRITE_SIZE/2);
    mSprite.setTextureRect(sf::IntRect(0,0,SPRITE_SIZE,SPRITE_SIZE));
    mAnimationDirection = CLOSING;
    mCurrentFrame = SPRITES_IN_TEXTURE;
}

void GamePlayer::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mSprite,states);
}

void GamePlayer::setMovingLeft()
{
    mDirection = LEFT;
    setVelocity(-SPEED,0);
    mSprite.setRotation(180);
}


void GamePlayer::setMovingRight()
{
    mDirection = RIGHT;
    setVelocity(SPEED,0);
    mSprite.setRotation(0);
}


void GamePlayer::setMovingUp()
{
    mDirection = UP;
    setVelocity(0,-SPEED);
    mSprite.setRotation(-90);
}


void GamePlayer::setMovingDown()
{
    mDirection = DOWN;
    setVelocity(0,SPEED);
    mSprite.setRotation(90);
}

void GamePlayer::updateCurrent(sf::Time dt)
{

    ++mFrameCounter;

    if (mFrameCounter > FRAME_COUNT) {
        if (mAnimationDirection == CLOSING) {
            --mCurrentFrame;
            mFrameCounter = 0;
            if (mCurrentFrame == 0) {
                mAnimationDirection = OPENING;
            }
        } else {
            ++mCurrentFrame;
            mFrameCounter = 0;
            if (mCurrentFrame == 4) {
                mAnimationDirection = CLOSING;
            }
        }

        mSprite.setTextureRect(sf::IntRect(SPRITE_SIZE * mCurrentFrame,0,SPRITE_SIZE,SPRITE_SIZE));
    }

    if (mDirection == LEFT && getPosition().x < SPRITE_SIZE / 2) return;
    if (mDirection == RIGHT && getPosition().x > mWindow.getSize().x - SPRITE_SIZE/2) return;
    if (mDirection == UP && getPosition().y < SPRITE_SIZE / 2) return;
    if (mDirection == DOWN && getPosition().y >mWindow.getSize().y - SPRITE_SIZE / 2) return;


    move(getVelocity() * dt.asSeconds());
}
