#include "������.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Mage::Mage() : Character(WSTR("������"), 1, 80, 18), mana(100), maxMana(100) {}

void Mage::attack(Character& target) {
    wcout << name << L"�� �⺻ ����: ���� źȯ!\n";
    target.takeDamage(attackPower);
}

void Mage::specialAttack(Character& target) {
    wcout << name << L"�� Ư�� ����: ���̾ (Fireball)! (1.5�� ���ݷ�, ���� -20)\n";
    try {
        if (mana < 20) {
            throw runtime_error("Mana shortage for Fireball.");
        }
        target.takeDamage(static_cast<int>(attackPower * 1.5));
        mana -= 20;
    }
    catch (const exception& e) {
        wcout << L"���� �߻�: " << e.what() << L"\n";
        wcout << L"�⺻ �������� ��ü�մϴ�.\n";
        attack(target);
    }
}

void Mage::resetHealth() {
    Character::resetHealth();
    mana = maxMana;
}

void Mage::showStatus() const {
    Character::showStatus();
    wcout << L" | ����: " << mana << L"/" << maxMana << L"\n";
}