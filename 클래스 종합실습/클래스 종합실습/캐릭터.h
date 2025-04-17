#ifndef 캐릭터_H
#define 캐릭터_H

#include <string>

// 유니코드 문자열 변환 매크로
#define WSTR(s) L##s

class Character {
protected:
    std::wstring name; // 유니코드 문자열
    int level;
    int health;
    int maxHealth;
    int attackPower;

public:
    Character(std::wstring name, int level, int health, int attackPower);
    virtual ~Character() = default;

    virtual void attack(Character& target) = 0;
    virtual void specialAttack(Character& target) = 0;
    virtual void resetHealth();
    virtual void showStatus() const;

    void takeDamage(int damage);
    bool isAlive() const;
    std::wstring getNameW() const; // 유니코드 이름
    std::string getName() const;   // 기존 호환성
};

#endif