#ifndef ĳ����_H
#define ĳ����_H

#include <string>

// �����ڵ� ���ڿ� ��ȯ ��ũ��
#define WSTR(s) L##s

class Character {
protected:
    std::wstring name; // �����ڵ� ���ڿ�
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
    std::wstring getNameW() const; // �����ڵ� �̸�
    std::string getName() const;   // ���� ȣȯ��
};

#endif