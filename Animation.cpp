#include"Animation.hpp"

Animation::Animation(std::string source, int frameWidth) : Drawable(source) {
    sf::IntRect dimentions = sprite.getTextureRect();
    numFramesX = dimentions.width / frameWidth;
    numFramesY = dimentions.height / frameWidth;
    this->frameWidth = frameWidth;
    frameX = frameY = 0;
    spriteRect = sf::IntRect(frameX, frameY, frameWidth, frameWidth);
    sprite.setTextureRect(spriteRect);
    delayTime = 0.1;
}

void Animation::reset() {
    frameX = frameY = 0;
    spriteRect = sf::IntRect(frameX, frameY, frameWidth, frameWidth);
    animDelay.restart();
}

void Animation::draw(sf::RenderWindow* window, float x, float y) {
    sprite.setPosition(x,y);
    window->draw(sprite);
    if(animDelay.getElapsedTime().asSeconds() > delayTime) {
        frameX++;
        if(frameX >= numFramesX) {
            frameX = 0;
            frameY++;
            if(frameY >= numFramesY) {
                frameY = 0;
            }
        }
        spriteRect = sf::IntRect(frameX*frameWidth, frameY*frameWidth, frameWidth, frameWidth);
        sprite.setTextureRect(spriteRect);
        animDelay.restart();
    }
}
