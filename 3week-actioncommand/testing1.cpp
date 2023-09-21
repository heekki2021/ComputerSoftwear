#include <iostream>
#include <windows.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 20x20 초록색 박스 출력
    SetConsoleTextAttribute(hConsole, 0x04);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::wcout << L"\u2B1B";
        }
        std::cout << std::endl;
    }

    // 커서를 초록색 박스의 중앙으로 이동
    int startRow = (20 - 11) / 2;
    int startCol = (20 - 11) / 2;

    // 가로 방향으로 시작 위치로 이동
    COORD coord;
    coord.X = startCol;
    coord.Y = startRow;

    SetConsoleCursorPosition(hConsole, coord);

    // 11x11 빨간색 박스를 초록색 박스 중앙에 출력
    SetConsoleTextAttribute(hConsole, 0x40); // 0x40은 배경색을 빨간색으로 설정
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            std::wcout << L"\u2B1B" << std::endl;
        }
        std::cout << std::endl;

        // 다음 줄의 시작 위치로 커서 이동
        coord.Y = startRow + i + 1;
        SetConsoleCursorPosition(hConsole, coord);
    }

    // 속성을 원래대로 복원
    SetConsoleTextAttribute(hConsole, 7); // 7은 기본 색상입니다.

    while (1) {

    }
    return 0;
}