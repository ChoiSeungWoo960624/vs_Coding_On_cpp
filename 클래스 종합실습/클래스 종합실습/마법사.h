#ifndef ������_H
#define ������_H

#include "ĳ����.h"

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