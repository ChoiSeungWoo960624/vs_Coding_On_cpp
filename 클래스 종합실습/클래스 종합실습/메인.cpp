#define NOMINMAX
#include "ĳ����.h"
#include "����.h"
#include "������.h"
#include "����.h"
#include "����.h"
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

// ĳ���� ���� �Լ�
shared_ptr<Character> chooseCharacter(const wstring& prompt) {
    wcout << prompt << L"\n1. ����\n2. ������\n3. ����\n����: ";
    int choice;
    while (!(wcin >> choice)) {
        wcout << L"���ڸ� �Է��ϼ���: ";
        wcin.clear();
        wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
    }

    switch (choice) {
    case 1:
        wcout << L"���縦 �����߽��ϴ�.\n";
        return make_shared<Warrior>();
    case 2:
        wcout << L"�����縦 �����߽��ϴ�.\n";
        return make_shared<Mage>();
    case 3:
        wcout << L"������ �����߽��ϴ�.\n";
        return make_shared<Rogue>();
    default:
        wcout << L"�߸��� �����Դϴ�. ����� �����մϴ�.\n";
        return make_shared<Warrior>();
    }
}

int main() {
    // Windows �ܼ� ����
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#endif

    // ������ ����
    wcout.imbue(locale("ko_KR.utf8"));

    // �÷��̾� ĳ���� ����
    shared_ptr<Character> player = chooseCharacter(WSTR("�÷��̾� ĳ���͸� �����ϼ���:"));

    BattleManager battleManager;
    bool gameContinue = true;

    while (gameContinue && player->isAlive()) {
        // ��� ĳ���� ����
        shared_ptr<Character> enemy = chooseCharacter(WSTR("��� ĳ���͸� �����ϼ���:"));

        wcout << L"\n--- " << player->getNameW() << L" vs " << enemy->getNameW() << L" ���� ���� ---\n";
        battleManager.startBattle(player, enemy);

        if (player->isAlive()) {
            wcout << L"\n���� ������ �����Ͻðڽ��ϱ�? (y/n): ";
            wchar_t cont;
            wcin >> cont;
            cont = tolower(cont);
            if (cont != L'y') {
                gameContinue = false;
            }
        }
        else {
            wcout << L"\n�й��߽��ϴ�. ������ ����˴ϴ�.\n";
            gameContinue = false;
        }
    }

    wcout << L"\n������ ����Ǿ����ϴ�.\n";
    return 0;
}
