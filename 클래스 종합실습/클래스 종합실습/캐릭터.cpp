#include "캐릭터.h"
#include <iostream>

using namespace std;

Character::Character(wstring name, int level, int health, int attackPower)
    : name(move(name)), level(level), health(health), maxHealth(health), attackPower(attackPower) {
}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    wcout << name << L"는 " << damage << L"의 피해를 입었습니다. (남은 체력: " << health << L")\n";
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
    // wstring을 UTF-8 string으로 변환
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
    wcout << L"이름: " << name << L" | 레벨: " << level << L" | 체력: " << health << L"/" << maxHealth
        << L" | 공격력: " << attackPower;
}