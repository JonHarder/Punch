#include"Player.hpp"

#include<iostream>

Player::Player(AssetManager* manager) : Agent("resources/test.png", manager) {
    punch = Ability();
}

void Player::update() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        move(sf::Vector2f(0.0,-speed));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        move(sf::Vector2f(-speed,0.0));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        move(sf::Vector2f(0.0,speed));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        move(sf::Vector2f(speed,0.0));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J) ) {
        if(punch.ready()) {
            punch.activate(this);
        }
    }
}
