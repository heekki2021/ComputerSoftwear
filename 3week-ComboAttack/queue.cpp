#include <iostream>
#define maxSize 30

using namespace std;

class Queue {

private:
	int front;
	int rear;
	int size;
	int* values;
	int number;

public:
	Queue() {
		size = maxSize;
		values = new int[size];

		front = 0;

		rear = 0;

		number = 0;
	}

	bool isEmpty() {
		if (number == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isFull() {
		if (number == size) {
			return true;
		}
		else {
			return false;
		}
	}


	void push(int value) {
		if (isFull() == true) {
			cout << "Queue is Full" << endl;
		}
		else {
			values[rear] = value;

			rear = (rear + 1) % size;
			//���� ť �۵���� ����� �Ѿ�� ������ �ͼ� ä��

			number = number + 1; //�迭�� ����ִ� �ε��� ��

		}
	}

	void pop() {
		if (isEmpty() == true) {
			cout << "Queue is Empty" << endl;

		}
		else {
			front = (front + 1) % size;

			number = number - 1;
		}
	}

	void print() {
		if (isEmpty() == true) {
			cout << "There is nothing" << endl;
		}
		else {
			int j = front;

			for (int i = 0; i < number; i++) {
				cout << values[j] << " ";
				j = (j + 1) % size;
			}
			cout << endl;
		}
	}


};