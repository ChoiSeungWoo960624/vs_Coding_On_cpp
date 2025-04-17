#include "����.h"
#include "����.h"
#include "������.h"
#include "����.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

using namespace std;

extern mt19937 gen;
extern uniform_int_distribution<int> dist100;

void BattleManager::startBattle(shared_ptr<Character> player, shared_ptr<Character> enemy) {
    wcout << L"\n--- ���� ���� ---\n";
    player->resetHealth();
    enemy->resetHealth();
    wcout << L"\n[�÷��̾� ����]\n";
    player->showStatus();
    wcout << L"\n[�� ����]\n";
    enemy->showStatus();
    wcout << L"\n";

    bool playerTurn = dist100(gen) < 50;
    wcout << (playerTurn ? player->getNameW() : enemy->getNameW()) << L"�� ������ ��ҽ��ϴ�!\n";
    this_thread::sleep_for(chrono::milliseconds(1000));

    while (player->isAlive() && enemy->isAlive()) {
        if (playerTurn) {
            wcout << L"\n[�÷��̾� ��]\n";
            int choice = dist100(gen);
            try {
                if (choice < 70) {
                    wcout << player->getNameW() << L"�� �⺻ ������ �����߽��ϴ�.\n";
                    player->attack(*enemy);
                }
                else {
                    wcout << player->getNameW() << L"�� Ư�� ������ �����߽��ϴ�.\n";
                    player->specialAttack(*enemy);
                }
            }
            catch (const exception& e) {
                wcout << L"���� �߻�: " << e.what() << L"\n";
                wcout << L"������ �����߽��ϴ�.\n";
            }
        }
        else {
            wcout << L"\n[�� ��]\n";
            int choice = dist100(gen);
            try {
                if (choice < 70) {
                    wcout << enemy->getNameW() << L"�� �⺻ ������ �����߽��ϴ�.\n";
                    enemy->attack(*player);
                }
                else {
                    wcout << enemy->getNameW() << L"�� Ư�� ������ �����߽��ϴ�.\n";
                    enemy->specialAttack(*player);
                }
            }
            catch (const exception& e) {
                wcout << L"���� �߻�: " << e.what() << L"\n";
                wcout << L"������ �����߽��ϴ�.\n";
            }
        }

        this_thread::sleep_for(chrono::milliseconds(1500));

        wcout << L"\n[���� ����]\n";
        wcout << player->getNameW() << L" ü��: " << (player->isAlive() ? L"����" : L"���") << L"\n";
        wcout << enemy->getNameW() << L" ü��: " << (enemy->isAlive() ? L"����" : L"���") << L"\n";

        playerTurn = !playerTurn;
    }

    if (player->isAlive()) {
        wcout << L"\n" << player->getNameW() << L"�� �������� �¸��߽��ϴ�!\n";
    }
    else {
        wcout << L"\n" << enemy->getNameW() << L"�� �������� �¸��߽��ϴ�. ���� ����.\n";
    }
}