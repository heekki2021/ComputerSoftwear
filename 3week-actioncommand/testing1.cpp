#include <iostream>
#include <windows.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 20x20 �ʷϻ� �ڽ� ���
    SetConsoleTextAttribute(hConsole, 0x04);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::wcout << L"\u2B1B";
        }
        std::cout << std::endl;
    }

    // Ŀ���� �ʷϻ� �ڽ��� �߾����� �̵�
    int startRow = (20 - 11) / 2;
    int startCol = (20 - 11) / 2;

    // ���� �������� ���� ��ġ�� �̵�
    COORD coord;
    coord.X = startCol;
    coord.Y = startRow;

    SetConsoleCursorPosition(hConsole, coord);

    // 11x11 ������ �ڽ��� �ʷϻ� �ڽ� �߾ӿ� ���
    SetConsoleTextAttribute(hConsole, 0x40); // 0x40�� ������ ���������� ����
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            std::wcout << L"\u2B1B" << std::endl;
        }
        std::cout << std::endl;

        // ���� ���� ���� ��ġ�� Ŀ�� �̵�
        coord.Y = startRow + i + 1;
        SetConsoleCursorPosition(hConsole, coord);
    }

    // �Ӽ��� ������� ����
    SetConsoleTextAttribute(hConsole, 7); // 7�� �⺻ �����Դϴ�.

    while (1) {

    }
    return 0;
}