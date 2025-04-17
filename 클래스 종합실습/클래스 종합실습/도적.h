#ifndef 도적_H
#define 도적_H

#include "캐릭터.h"

class Rogue : public Character {
public:
    Rogue();
    void attack(Character& target) override;
    void specialAttack(Character& target) override;
};

#endif