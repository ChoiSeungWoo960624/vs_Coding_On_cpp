#ifndef ����_H
#define ����_H

#include "ĳ����.h"

class Rogue : public Character {
public:
    Rogue();
    void attack(Character& target) override;
    void specialAttack(Character& target) override;
};

#endif