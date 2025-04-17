#ifndef 마법사_H
#define 마법사_H

#include "캐릭터.h"

class Mage : public Character {
private:
    int mana;
    int maxMana;

public:
    Mage();
    void attack(Character& target) override;
    void specialAttack(Character& target) override;
    void resetHealth() override;
    void showStatus() const override;
};

#endif