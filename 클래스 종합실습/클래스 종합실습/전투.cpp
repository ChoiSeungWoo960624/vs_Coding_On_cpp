#include "전투.h"
#include "전사.h"
#include "마법사.h"
#include "도적.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

using namespace std;

extern mt19937 gen;
extern uniform_int_distribution<int> dist100;

void BattleManager::startBattle(shared_ptr<Character> player, shared_ptr<Character> enemy) {
    wcout << L"\n--- 전투 시작 ---\n";
    player->resetHealth();
    enemy->resetHealth();
    wcout << L"\n[플레이어 상태]\n";
    player->showStatus();
    wcout << L"\n[적 상태]\n";
    enemy->showStatus();
    wcout << L"\n";

    bool playerTurn = dist100(gen) < 50;
    wcout << (playerTurn ? player->getNameW() : enemy->getNameW()) << L"가 선공을 잡았습니다!\n";
    this_thread::sleep_for(chrono::milliseconds(1000));

    while (player->isAlive() && enemy->isAlive()) {
        if (playerTurn) {
            wcout << L"\n[플레이어 턴]\n";
            int choice = dist100(gen);
            try {
                if (choice < 70) {
                    wcout << player->getNameW() << L"가 기본 공격을 선택했습니다.\n";
                    player->attack(*enemy);
                }
                else {
                    wcout << player->getNameW() << L"가 특수 공격을 선택했습니다.\n";
                    player->specialAttack(*enemy);
                }
            }
            catch (const exception& e) {
                wcout << L"예외 발생: " << e.what() << L"\n";
                wcout << L"공격이 실패했습니다.\n";
            }
        }
        else {
            wcout << L"\n[적 턴]\n";
            int choice = dist100(gen);
            try {
                if (choice < 70) {
                    wcout << enemy->getNameW() << L"가 기본 공격을 선택했습니다.\n";
                    enemy->attack(*player);
                }
                else {
                    wcout << enemy->getNameW() << L"가 특수 공격을 선택했습니다.\n";
                    enemy->specialAttack(*player);
                }
            }
            catch (const exception& e) {
                wcout << L"예외 발생: " << e.what() << L"\n";
                wcout << L"공격이 실패했습니다.\n";
            }
        }

        this_thread::sleep_for(chrono::milliseconds(1500));

        wcout << L"\n[현재 상태]\n";
        wcout << player->getNameW() << L" 체력: " << (player->isAlive() ? L"생존" : L"사망") << L"\n";
        wcout << enemy->getNameW() << L" 체력: " << (enemy->isAlive() ? L"생존" : L"사망") << L"\n";

        playerTurn = !playerTurn;
    }

    if (player->isAlive()) {
        wcout << L"\n" << player->getNameW() << L"가 전투에서 승리했습니다!\n";
    }
    else {
        wcout << L"\n" << enemy->getNameW() << L"가 전투에서 승리했습니다. 게임 오버.\n";
    }
}