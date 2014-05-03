#include"Agent.hpp"
#include<iostream>

Agent::Agent(std::string imageSrc, AssetManager* manager) {
    drawPtr = manager->addAsset(imageSrc);
    position = sf::Vector2f(0.0,0.0);
    speed = 5.0;
    setDirection(Up);
}

void Agent::setDirection(Direction dir) {
    direction = dir;
    float w = drawPtr->getSprite()->getLocalBounds().width;
    float h = drawPtr->getSprite()->getLocalBounds().height;
    drawPtr->getSprite()->setOrigin(w/2,h/2);
    switch(dir) {
    case Up:
        drawPtr->setRotation(0);
        break;
    case Left:
        drawPtr->setRotation(-90);
        break;
    case Down:
        drawPtr->setRotation(180);
        break;
    case Right:
        drawPtr->setRotation(90);
        break;
    }
}

void Agent::move(sf::Vector2f direction) {
    position += direction;
    // (+,0) = right
    // (0,+) = down
    // (-,0) = left
    // (0,-) = up
          
    if(direction.x > 0 && direction.y == 0) {
        setDirection(Right);
    }
    if(direction.x == 0 && direction.y > 0) {
        setDirection(Down);
    }
    if(direction.x < 0 && direction.y == 0) {
        setDirection(Left);
    }
    if(direction.x == 0 && direction.y < 0) {
        setDirection(Up);
    }
}

void Agent::update() {

}

Direction Agent::getDir() {
    return direction;
}

void Agent::draw(sf::RenderWindow* window) {
    drawPtr->setPosition(position);
    window->draw(*drawPtr->getSprite());
}

sf::Vector2f Agent::getSize() {
    float width = drawPtr->getSprite()->getTextureRect().width;
    float height = drawPtr->getSprite()->getTextureRect().height;
    return sf::Vector2f(width, height);
}

bool Agent::intersects(Agent other) {
    sf::Rect<float> thisBox = getPositionRect();
    sf::Rect<float> otherBox = other.getPositionRect();
    return thisBox.intersects(otherBox);
}

bool Agent::collide(Agent other) {
    return intersects(other);
}

sf::Rect<float> Agent::getPositionRect() {
    return sf::Rect<float>(getPosition(), getSize());
}

sf::Vector2f Agent::getPosition() {
    return position;
}

