#ifndef ����_H
#define ����_H

#include "ĳ����.h"

class Warrior : public Character {
public:
    Warrior();
    void attack(Character& target) override;
    void specialAttack(Character& target) override;
};

#endif