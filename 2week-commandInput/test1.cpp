#include <iostream>
#include <windows.h>
#include <conio.h>

int main() {
    std::cout << "Enter text (Press ESC to exit): ";

    char ch;
    while (true) {
        // ESC Ű�� ���ȴ��� Ȯ��
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            ExitProcess(0);  // ���μ��� ����
        }
        std::cout << "Enter text (Press ESC to exit): ";

        // _kbhit()�� Ű���� ���ۿ� ���ڰ� �ִ��� Ȯ��
        if (_kbhit()) {
            ch = _getch();  // ���� �б�
            std::cout << ch;
        }

        Sleep(50);  // CPU ��뷮�� ���̱� ���� ����
    }

    return 0;
}





