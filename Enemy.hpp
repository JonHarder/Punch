#ifndef _ENEMY_H
#define _ENEMY_H

#include"Agent.hpp"

class Enemy : public Agent {
public:
    Enemy(std::string imageSrc, AssetManager* manager);
    void update(sf::Vector2f playerPos);
};

#endif // _ENEMY_H
