#include <iostream>
#include <windows.h>
#include <string>
//-------------------------------------------
#include <chrono>
#include <thread>

std::thread gThread;

void escFn() {

	while (true) {
		if (GetAsyncKeyState(VK_ESCAPE)) {
			ExitProcess(0);  // ���μ��� ����
		}
		Sleep(50);  // CPU ��뷮�� ���̱� ���� ����
		//std::this_thread::sleep_for(std::chrono::seconds(3));

	}
	
}

void threadCaller() {
	gThread = std::thread(escFn);
}

int main(void)
{

	std::cout << "Press ESC to exit..." << std::endl;
	std::string input;


	std::cout << "\033[34mHello, World\033[0m" << std::endl;

	std::cout << "\033[32m������ ������ ���ڸ� ����~\033[0m" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	threadCaller();

	while (true)
	{
		

		std::cout << "\033[31mcommand>\033[0m" << std::flush;


		std::getline(std::cin, input); // �� ���� �Է¹���



		if (input == "q") {
				std::cout << "\033[35mq ����\033[0m" << std::endl;
				
		}
		else if (input == "w") {
				std::cout << "\033[35mw ����\033[0m" << std::endl;
		}
		else if (input == "e") {
				std::cout << "\033[35me ����\033[0m" << std::endl;
		}
		else if (input == "r") {
				std::cout << "\033[35mr ����\033[0m" << std::endl;

		}
		else {
				std::cout << "\033[31m�ԼҸ� �������� QWER �� �Է�\033[0m" << std::endl;

		}


	}
	


	return 0;
}
