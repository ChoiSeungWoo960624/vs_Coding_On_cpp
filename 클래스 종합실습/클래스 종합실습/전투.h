#ifndef 전투_H
#define 전투_H

#include <memory>
#include "캐릭터.h"

class BattleManager {
public:
    void startBattle(std::shared_ptr<Character> player, std::shared_ptr<Character> enemy);
};

#endif