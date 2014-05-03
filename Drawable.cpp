#include"Drawable.hpp"

Drawable::Drawable(std::string imageSrc) {
    tex.loadFromFile(imageSrc);
    sprite.setTexture(tex);
}

void Drawable::draw(sf::RenderWindow* window, float x, float y) {
    sprite.setPosition(x,y);
    window->draw(sprite);
}

void Drawable::setPosition(sf::Vector2f p) {
    sprite.setPosition(p);
}

sf::Sprite* Drawable::getSprite() {
    return &sprite;
}

void Drawable::setRotation(float rotation) {
    sprite.setRotation(rotation);
}
