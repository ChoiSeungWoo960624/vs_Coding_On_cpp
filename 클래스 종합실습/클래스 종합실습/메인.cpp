#define NOMINMAX
#include "캐릭터.h"
#include "전사.h"
#include "마법사.h"
#include "도적.h"
#include "전투.h"
#include <iostream>
#include <memory>
#include <random>
#include <cctype>
#include <string>
#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#endif
#include <limits>
#include <locale>

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist100(0, 99);

// 캐릭터 선택 함수
shared_ptr<Character> chooseCharacter(const wstring& prompt) {
    wcout << prompt << L"\n1. 전사\n2. 마법사\n3. 도적\n선택: ";
    int choice;
    while (!(wcin >> choice)) {
        wcout << L"숫자를 입력하세요: ";
        wcin.clear();
        wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
    }

    switch (choice) {
    case 1:
        wcout << L"전사를 선택했습니다.\n";
        return make_shared<Warrior>();
    case 2:
        wcout << L"마법사를 선택했습니다.\n";
        return make_shared<Mage>();
    case 3:
        wcout << L"도적을 선택했습니다.\n";
        return make_shared<Rogue>();
    default:
        wcout << L"잘못된 선택입니다. 전사로 시작합니다.\n";
        return make_shared<Warrior>();
    }
}

int main() {
    // Windows 콘솔 설정
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#endif

    // 로케일 설정
    wcout.imbue(locale("ko_KR.utf8"));

    // 플레이어 캐릭터 선택
    shared_ptr<Character> player = chooseCharacter(WSTR("플레이어 캐릭터를 선택하세요:"));

    BattleManager battleManager;
    bool gameContinue = true;

    while (gameContinue && player->isAlive()) {
        // 상대 캐릭터 선택
        shared_ptr<Character> enemy = chooseCharacter(WSTR("상대 캐릭터를 선택하세요:"));

        wcout << L"\n--- " << player->getNameW() << L" vs " << enemy->getNameW() << L" 전투 시작 ---\n";
        battleManager.startBattle(player, enemy);

        if (player->isAlive()) {
            wcout << L"\n다음 전투를 진행하시겠습니까? (y/n): ";
            wchar_t cont;
            wcin >> cont;
            cont = tolower(cont);
            if (cont != L'y') {
                gameContinue = false;
            }
        }
        else {
            wcout << L"\n패배했습니다. 게임이 종료됩니다.\n";
            gameContinue = false;
        }
    }

    wcout << L"\n게임이 종료되었습니다.\n";
    return 0;
}
