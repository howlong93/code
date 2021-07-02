#include <iostream>

using namespace std;

#define _size 10

int queue[_size] = {0};
int front = 0, rear = 0;

void enqueue(int x);
void dequeue();
bool isFull();
bool isEmpty();

int main() { //true size of queue = _size - 1
    int x, y;
    while (cin >> x) {
        if (x == 1) { //enqueue
            cin >> y;
            enqueue(y);
        } 
		else if (x == 2) { //dequeue
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

    rear = (rear+1)%10;
    queue[rear] = x;
}

void dequeue() {
    if (isEmpty()) {
        cout << "queue is empty\n";
        return;  //結束函式
    }

    front = (front+1)%10;
    cout << queue[front] << '\n';
    queue[front] = 0;
}

bool isFull() {
    return ((rear+1)%_size) == front;
}

bool isEmpty() {
    return rear == front;
}
