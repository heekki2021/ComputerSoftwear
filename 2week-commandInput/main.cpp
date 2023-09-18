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
			ExitProcess(0);  // 프로세스 종료
		}
		Sleep(50);  // CPU 사용량을 줄이기 위한 슬립
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

	std::cout << "\033[32m승지는 언제나 제자리 걸음~\033[0m" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	threadCaller();

	while (true)
	{
		

		std::cout << "\033[31mcommand>\033[0m" << std::flush;


		std::getline(std::cin, input); // 한 줄을 입력받음



		if (input == "q") {
				std::cout << "\033[35mq 누름\033[0m" << std::endl;
				
		}
		else if (input == "w") {
				std::cout << "\033[35mw 누름\033[0m" << std::endl;
		}
		else if (input == "e") {
				std::cout << "\033[35me 누름\033[0m" << std::endl;
		}
		else if (input == "r") {
				std::cout << "\033[35mr 누름\033[0m" << std::endl;

		}
		else {
				std::cout << "\033[31m쌉소리 하지말고 QWER 만 입력\033[0m" << std::endl;

		}


	}
	


	return 0;
}
