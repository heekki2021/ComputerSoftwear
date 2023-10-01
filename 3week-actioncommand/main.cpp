#include <iostream>
#include <windows.h>
#include "queue.cpp"
#include <chrono>
#include <thread>

std::thread waitingThread;

int timeCheck = 0;


Queue q; //전역 버퍼용 큐

int keyInputCheck() {
    for (int i = 8; i <= 255; i++) {
        if (GetAsyncKeyState(i) & 0x8000) {
            std::cout << i << std::endl;
            q.push(i);
            return 0;
        }
    }
    return 0;

}

void waiting() {
    this_thread::sleep_for(std::chrono::seconds(3));
    timeCheck = 3;
}

void threadCaller()
{
    waitingThread = std::thread(waiting);
}

int buffer(int keyCode) {
    q.push(keyCode);
    std::cout << "3초 동안 대기합니다. " << std::endl;
    threadCaller();
    std::cout << "testing1" << std::endl;

    while (timeCheck == 0) {

        keyInputCheck();
        Sleep(100);

    }
    std::cout << "testing3" << std::endl;

    std::cout << "입력값은 = " << std::endl;
    q.print();
    return 0;
}





int main() {
    int check = 0;
    int keyPress = 0;


    while (true) {
        for (int i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) & 0x8000) {
                std::cout << "키가 눌렸다" << std::endl;
                buffer(i);
                break;
            } 
        }
        
        
        while (!q.isEmpty()) {
            q.pop();
        }
        timeCheck = 0;
        //waitingThread.join();

    }
    
    int a;

        std::cin >> a;


  /*  Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(11);
    q.push(20);
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();*/

    return 0;
   
}