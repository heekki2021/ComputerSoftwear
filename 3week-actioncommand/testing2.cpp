//#include <windows.h>
//
//int main() {
//    // �ܼ� �ڵ� ���
//    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // �ʷϻ����� �ؽ�Ʈ ���� ����
//    SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN);
//
//    // ���簢�� �׸���
//    int size = 10; // ���簢���� ũ��
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            // �ֿܼ� ���� ���
//            putchar('#');
//        }
//        // ���� �ٷ� �̵�
//        putchar('\n');
//    }
//
//    // �ؽ�Ʈ ���� ������� ����
//    SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//
//    return 0;
//}