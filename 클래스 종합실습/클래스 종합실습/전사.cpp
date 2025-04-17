#include "전사.h"
#include <iostream>

using namespace std;

Warrior::Warrior() : Character(WSTR("전사"), 1, 100, 15) {}

void Warrior::attack(Character& target) {
    wcout << name << L"의 기본 공격: 강력한 베기!\n";
    target.takeDamage(attackPower);
}

void Warrior::specialAttack(Character& target) {
    wcout << name << L"의 특수 공격: 강력한 일격 (Power Strike)! (2배 공격력, 체력 -5)\n";
    target.takeDamage(attackPower * 2);
    takeDamage(5);
}