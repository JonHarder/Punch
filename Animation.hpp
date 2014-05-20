#ifndef _ANIMATION_H
#define _ANIMATION_H

#include"Drawable.hpp"

class Animation : public Drawable {
public:
    Animation(std::string source, int xFrames, int framesY, int frameWidth);
                                                // and the number of frames you want
                                                // to be a part of the animation
    
    void draw(sf::RenderWindow* window, float x, float y); // gives the drawable sprite for next renderable frame
    void reset(); // resets the counter back to initial frame
private:
    sf::Clock animDelay;
    float delayTime;
    int frameX, frameY;
    int numFramesX, numFramesY;
    int frameWidth;
    sf::IntRect spriteRect;
};

#endif // _ANIMATION_H
