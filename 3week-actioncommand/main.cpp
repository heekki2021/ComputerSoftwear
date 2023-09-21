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
//	// 0x04는 전경색(텍스트 색상)을 빨간색으로, 0x80은 배경색을 빨간색으로 설정합니다.
//	SetConsoleTextAttribute(hConsole, 0x84);
//
//	// 빨간색 배경 위에 빈 공간(박스)를 출력
//	std::cout << "      " << std::endl;
//	std::cout << "      " << std::endl;
//	std::cout << "      " << std::endl;
//
//	// 속성을 원래대로 복원
//	//SetConsoleTextAttribute(hConsole, 7); // 7은 기본 색상입니다.
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







    // 0x40은 배경색을 빨간색으로 설정합니다.
    SetConsoleTextAttribute(hConsole, 0x40);

    // 빨간색 배경 위에 빈 공간(박스)를 출력
    std::cout << L"\u2B1B" << std::endl;
    std::cout << L"\u2B1B" << std::endl;


    // 속성을 원래대로 복원
    SetConsoleTextAttribute(hConsole, 7); // 7은 기본 색상입니다.

    return 0;
}