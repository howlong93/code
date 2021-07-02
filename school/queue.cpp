#include <iostream>

using namespace std;

#define _size 10

int queue[_size] = {0};
int front = -1, rear = -1;

void enqueue(int x);
void dequeue();
bool isFull();
bool isEmpty();

int main() {
    int x, y;
    while (cin >> x) {
        if (x == 1) { //enqueue
            cin >> y;
            enqueue(y);
        } 
		else { //dequeue
            dequeue();
		}
    }

    return 0;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "queue is full\n";
        return;  //結束函式
    }

    rear++;
    queue[rear] = x;
}

void dequeue() {
    if (isEmpty()) {
        cout << "queue is empty\n";
        return;  //結束函式
    }

    front++;
    cout << queue[front] << '\n';
    queue[front] = 0;
}

bool isFull() {
    return rear == _size - 1;
}

bool isEmpty() {
    return rear == front;
}
