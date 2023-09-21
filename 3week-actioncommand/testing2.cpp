//#include <windows.h>
//
//int main() {
//    // 콘솔 핸들 얻기
//    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // 초록색으로 텍스트 색상 설정
//    SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
//
//    // 정사각형 그리기
//    int size = 10; // 정사각형의 크기
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            // 콘솔에 문자 출력
//            putchar('#');
//        }
//        // 다음 줄로 이동
//        putchar('\n');
//    }
//
//    // 텍스트 색상 원래대로 복원
//    SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//
//    return 0;
//}