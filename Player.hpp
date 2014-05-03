#ifndef _PLAYER_H
#define _PLAYER_H

#include"Agent.hpp"
#include"Ability.hpp"

class Player : public Agent {
public:
    Player(AssetManager* manager);
    void update();
private:
    Ability punch;
};

#endif // _PLAYER_H
