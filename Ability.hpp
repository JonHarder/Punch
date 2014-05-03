#ifndef _ABILITY_H
#define _ABILITY_H

/* TODO: have a way of applying damage to targets
 *
 */

#include"Agent.hpp"
#include<SFML/System.hpp>

enum Range{melee, ranged};

class Ability {
public:
    Ability();
    float knockBack();
    int getCooldown();
    bool activate(Agent* self);
    bool ready();
private:
    float followThrough; // how far this action will carry you forward
    float damage;  // how much damage will be applied to target
    sf::Clock timer;
    float cooldown; // time in seconds until you can use ability again
    Range range;
};

#endif // _ABILITY_H
