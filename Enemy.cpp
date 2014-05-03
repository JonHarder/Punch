#include"Enemy.hpp"
#include<iostream>
#include<cmath>

Enemy::Enemy(std::string imageSrc, AssetManager* manager) :
    Agent(imageSrc, manager) {
    speed = 3.0;
}

void Enemy::update(sf::Vector2f playerPos) {
    // chase the player
    sf::Vector2f pos = getPosition();
    float diffX = pos.x - playerPos.x;
    float diffY = pos.y - playerPos.y;
    float x,y = 0;
    float followBuffer = 4.0;

    // horizontal movement
    if(diffX > followBuffer) {
        x = -speed;
    }
    if(diffX < followBuffer) {
        x = speed;
    }

    // vertical movement
    if(diffY > followBuffer) {
        y = -speed;
    }
    if(diffY < followBuffer) {
        y = speed;
    }

    // make diagonal movement cost the same as solo horiz or vert
    if(x && y) {
        if(x < 0) {
            x = -sqrt(abs(x));
        } else {
            x = sqrt(x);
        }
        if(y < 0) {
            y = -sqrt(abs(y));
        } else {
            y = sqrt(y);
        }
    } 

    if(abs(diffX) <= speed) {
        move(sf::Vector2f(diffX, 0));
        return;
    }
    if(abs(diffY) <= speed) {
        move(sf::Vector2f(0, diffY));
        return;
    }
    
    move(sf::Vector2f(x,y));
}
