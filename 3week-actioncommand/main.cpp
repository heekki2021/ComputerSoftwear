//#include<iostream>
//#include <windows.h>
//
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main(void) {
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// 0x04�� �����(�ؽ�Ʈ ����)�� ����������, 0x80�� ������ ���������� �����մϴ�.
//	SetConsoleTextAttribute(hConsole, 0x84);
//
//	// ������ ��� ���� �� ����(�ڽ�)�� ���
//	std::cout << "      " << std::endl;
//	std::cout << "      " << std::endl;
//	std::cout << "      " << std::endl;
//
//	// �Ӽ��� ������� ����
//	//SetConsoleTextAttribute(hConsole, 7); // 7�� �⺻ �����Դϴ�.
//
//	return 0;
//
//
//	while (true)
//	{
//
//	}
//	return 0;
//
//
//	//while (true)
//	//{
//	//	for (int i = 0; i < 50; i++) {
//	//		std::wcout << L"\u2B1B" << std::endl;
//
//	//		for (int j = 0; i < 80; j++) {
//
//	//		}
//	//	}
//	//}
//}
//
//
#include <iostream>
#include <windows.h>

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



    for (int i = 0; i < 51; i++) {
        
    }







    // 0x40�� ������ ���������� �����մϴ�.
    SetConsoleTextAttribute(hConsole, 0x40);

    // ������ ��� ���� �� ����(�ڽ�)�� ���
    std::cout << L"\u2B1B" << std::endl;
    std::cout << L"\u2B1B" << std::endl;


    // �Ӽ��� ������� ����
    SetConsoleTextAttribute(hConsole, 7); // 7�� �⺻ �����Դϴ�.

    return 0;
}