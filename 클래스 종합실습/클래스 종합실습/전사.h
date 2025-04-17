#ifndef 전사_H
#define 전사_H

#include "캐릭터.h"

class Warrior : public Character {
public:
    Warrior();
    void attack(Character& target) override;
    void specialAttack(Character& target) override;
};

#endif