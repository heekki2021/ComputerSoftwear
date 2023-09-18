#include <iostream>
#include <windows.h>
#include <conio.h>

int main() {
    std::cout << "Enter text (Press ESC to exit): ";

    char ch;
    while (true) {
        // ESC 키가 눌렸는지 확인
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            ExitProcess(0);  // 프로세스 종료
        }
        std::cout << "Enter text (Press ESC to exit): ";

        // _kbhit()은 키보드 버퍼에 문자가 있는지 확인
        if (_kbhit()) {
            ch = _getch();  // 문자 읽기
            std::cout << ch;
        }

        Sleep(50);  // CPU 사용량을 줄이기 위한 슬립
    }

    return 0;
}





