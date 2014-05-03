#ifndef _AGENT_H
#define _AGENT_H

#include<SFML/Graphics.hpp>
#include"Drawable.hpp"
#include"AssetManager.hpp"

enum Direction{Left, Up, Down, Right};

class Agent {
public:
    Agent(std::string imageSrc, AssetManager* manager);
    void draw(sf::RenderWindow* window);
    void update();
    void move(sf::Vector2f direction);
    Direction getDir();
    bool collide(Agent other);
    sf::Vector2f getPosition();
    sf::Rect<float> getPositionRect();
    sf::Vector2f getSize();
    bool intersects(Agent other);
protected:
    void setDirection(Direction dir);
    float speed;
private:
    sf::Vector2f position;
    Direction direction;
    Drawable* drawPtr;
};

#endif // _AGENT_H
