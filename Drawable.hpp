#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include<SFML/Graphics.hpp>

class Drawable {
public:
    Drawable(std::string imageSrc);
    void draw(sf::RenderWindow* window, float x, float y);
    void setPosition(sf::Vector2f p);
    sf::Sprite* getSprite();
    void setRotation(float rotation);
protected:
    sf::Sprite sprite;
private:
    sf::Texture tex;
};

#endif // _DRAWABLE_H
