#include "����.h"
#include <iostream>

using namespace std;

Warrior::Warrior() : Character(WSTR("����"), 1, 100, 15) {}

void Warrior::attack(Character& target) {
    wcout << name << L"�� �⺻ ����: ������ ����!\n";
    target.takeDamage(attackPower);
}

void Warrior::specialAttack(Character& target) {
    wcout << name << L"�� Ư�� ����: ������ �ϰ� (Power Strike)! (2�� ���ݷ�, ü�� -5)\n";
    target.takeDamage(attackPower * 2);
    takeDamage(5);
}