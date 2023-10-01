#include <iostream>
#include <windows.h>
#include "queue.cpp"
#include <chrono>
#include <thread>

std::thread waitingThread;
std::thread gThread;
std::thread keyBufferThread;


int timeCheck = 0;
int keyPressed = 0;

Queue q; //전역 버퍼용 큐


int keyInputCheck() {
    
        for (int i = 8; i <= 255; i++) {
            if (i != VK_ESCAPE && (GetAsyncKeyState(i) & 0x8001) && (keyPressed == 0)) {
                std::cout << i << std::endl;
                q.push(i);
                std::cout << "키 down" << std::endl;
                keyPressed = 1;
                return 0;
            }
        }
        return 0;
}

int nonKeyInputCheck() {

        for (int i = 8; i <= 255; i++) {
            if (i != VK_ESCAPE && (GetAsyncKeyState(i) & 0x0001)&&(keyPressed == 1)) {
                std::cout << "키 up" << std::endl;
                keyPressed = 0;
                
                break;
            }
        }
        return 0;
}


void waiting() {
    this_thread::sleep_for(std::chrono::seconds(3));
    timeCheck = 3;
}



void escFn() {

    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE)) {
            ExitProcess(0);  // 프로세스 종료
        }
        //Sleep(50);  // CPU 사용량을 줄이기 위한 슬립
        //std::this_thread::sleep_for(std::chrono::seconds(3));

    }
}

void threadCaller1()
{
    waitingThread = std::thread(waiting);
}



int keyBuffer(int keyCode) {
    //q.push(keyCode);
    std::cout << "3초 동안 대기합니다. " << std::endl;
    threadCaller1();
    std::cout << "testing1" << std::endl;
    q.push(keyCode);
    while (timeCheck == 0) {

        nonKeyInputCheck();
        keyInputCheck();
        
        /*Sleep(100);
        std::cout << "testing3" << std::endl;*/

    }
    std::cout << "testing4" << std::endl;

    std::cout << "입력값은 = " << std::endl;
    q.print();
    
    waitingThread.join();
    return 0;
}



void threadCaller2() {
    gThread = std::thread(escFn);
}

void threadCaller3(t1) {
    t1 = std::thread(keyBuffer);
    t1.join();
}



int main() {
   

    threadCaller2();


    while (true) {
        for (int i = 8; i <= 255; i++) {
            if (i != VK_ESCAPE && (GetAsyncKeyState(i) & 0x8000)) {
                std::cout << "키가 눌렸다" << std::endl;
                int keyPressed = 1;
                //buffer(i);
                threadCaller3(keyBufferThread);
                keyBufferThread.join();
                std::cout << "빠져나왔당" << std::endl;

                break;
            }
        }


        while (!q.isEmpty() == true) {
            q.pop();
        }
        timeCheck = 0;

    }


    return 0;

}