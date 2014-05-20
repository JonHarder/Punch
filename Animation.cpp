#include"Animation.hpp"

Animation::Animation(std::string source, int xFrames, int yFrames, int frameWidth) : Drawable(source) {
    numFramesX = xFrames;
    numFramesY = yFrames;
    this->frameWidth = frameWidth;
    frameX = frameY = 0;
    spriteRect = sf::IntRect(frameX, frameY, frameWidth, frameWidth);
    sprite.setTextureRect(spriteRect);
    delayTime = 0.25;
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
