#ifndef ����_H
#define ����_H

#include <memory>
#include "ĳ����.h"

class BattleManager {
public:
    void startBattle(std::shared_ptr<Character> player, std::shared_ptr<Character> enemy);
};

#endif