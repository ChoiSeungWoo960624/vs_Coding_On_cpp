#include "도적.h"
#include <iostream>
#include <random>

using namespace std;

extern mt19937 gen;
extern uniform_int_distribution<int> dist100;

Rogue::Rogue() : Character(WSTR("도적"), 1, 90, 12) {}

void Rogue::attack(Character& target) {
    wcout << name << L"의 기본 공격: 빠른 연속타!\n";
    target.takeDamage(attackPower);
}

void Rogue::specialAttack(Character& target) {
    wcout << name << L"의 특수 공격: 급습 (Ambush)! (70% 확률로 3배 공격력)\n";
    int roll = dist100(gen);
    if (roll < 70) {
        wcout << L"급습 성공!\n";
        target.takeDamage(attackPower * 3);
    }
    else {
        wcout << L"급습 실패! 피해를 주지 못했습니다.\n";
    }
}