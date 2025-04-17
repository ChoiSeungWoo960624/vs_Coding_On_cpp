#include "마법사.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Mage::Mage() : Character(WSTR("마법사"), 1, 80, 18), mana(100), maxMana(100) {}

void Mage::attack(Character& target) {
    wcout << name << L"의 기본 공격: 마법 탄환!\n";
    target.takeDamage(attackPower);
}

void Mage::specialAttack(Character& target) {
    wcout << name << L"의 특수 공격: 파이어볼 (Fireball)! (1.5배 공격력, 마나 -20)\n";
    try {
        if (mana < 20) {
            throw runtime_error("Mana shortage for Fireball.");
        }
        target.takeDamage(static_cast<int>(attackPower * 1.5));
        mana -= 20;
    }
    catch (const exception& e) {
        wcout << L"예외 발생: " << e.what() << L"\n";
        wcout << L"기본 공격으로 대체합니다.\n";
        attack(target);
    }
}

void Mage::resetHealth() {
    Character::resetHealth();
    mana = maxMana;
}

void Mage::showStatus() const {
    Character::showStatus();
    wcout << L" | 마나: " << mana << L"/" << maxMana << L"\n";
}