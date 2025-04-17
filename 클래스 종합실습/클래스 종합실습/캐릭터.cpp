#include "ĳ����.h"
#include <iostream>

using namespace std;

Character::Character(wstring name, int level, int health, int attackPower)
    : name(move(name)), level(level), health(health), maxHealth(health), attackPower(attackPower) {
}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    wcout << name << L"�� " << damage << L"�� ���ظ� �Ծ����ϴ�. (���� ü��: " << health << L")\n";
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::resetHealth() {
    health = maxHealth;
}

wstring Character::getNameW() const {
    return name;
}

string Character::getName() const {
    // wstring�� UTF-8 string���� ��ȯ
    string result;
    for (wchar_t wc : name) {
        if (wc <= 0x7F) {
            result += static_cast<char>(wc);
        }
        else if (wc <= 0x7FF) {
            result += static_cast<char>(0xC0 | ((wc >> 6) & 0x1F));
            result += static_cast<char>(0x80 | (wc & 0x3F));
        }
        else {
            result += static_cast<char>(0xE0 | ((wc >> 12) & 0x0F));
            result += static_cast<char>(0x80 | ((wc >> 6) & 0x3F));
            result += static_cast<char>(0x80 | (wc & 0x3F));
        }
    }
    return result;
}

void Character::showStatus() const {
    wcout << L"�̸�: " << name << L" | ����: " << level << L" | ü��: " << health << L"/" << maxHealth
        << L" | ���ݷ�: " << attackPower;
}