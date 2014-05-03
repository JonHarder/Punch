#include"Ability.hpp"

Ability::Ability() {
    cooldown = 0.15;
    timer = sf::Clock();
    followThrough = 20.0;
    damage = 10.0;
    range = melee;
}

float Ability::knockBack() {
    return followThrough;
}

int Ability::getCooldown() {
    return timer.getElapsedTime().asSeconds();
}

bool Ability::ready() {
    return timer.getElapsedTime().asSeconds() > cooldown;
}

bool Ability::activate(Agent* self) {
    if(ready()) {
        timer.restart();
        switch(self->getDir()) {
        case Up:
            self->move(sf::Vector2f(0.0,-knockBack()));
            break;
        case Left:
            self->move(sf::Vector2f(-knockBack(), 0.0));
            break;
        case Right:
            self->move(sf::Vector2f(knockBack(), 0.0));
            break;
        case Down:
            self->move(sf::Vector2f(0.0,knockBack()));
            break;
        }

        return true;
        // apply damage
        // apply knockback if any
    } else {
        return false;
    }
}
