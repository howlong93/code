#include <iostream>

#define _size 10

using namespace std;

int stack[_size] = {0};
int top_pos = -1;

bool isFull();
bool isEmpty();
void top(); //查詢最上面的值
void push(int x);
void pop();

int main()
{
	int x, y;
	while (cin >> x) {
		if (x == 1) { //push
			cin >> y;
			push(y);
		}
		else if (x == 2) { //pop
			pop();
		}
		else if (x == 3) { //top value
			top();
		}
	}
    return 0;
}

bool isEmpty() {
    return top_pos == -1;
}

bool isFull() {
	return top_pos == _size-1;
}

void push(int x) {
    if ( isFull() ) {
        cout << "stack is full\n";
        return;
    }
   
    top_pos++;
    stack[top_pos] = x;
}

void pop() {
    if ( isEmpty() ) {
        cout << "stack is empty\n";
        return;
    }
   
    top(); //輸出被pop的值
    stack[top_pos] = 0;
    top_pos--;
}

void top() {
    if ( isEmpty() ) {
        cout << "stack is empty\n";
        return;
    }
   
    cout << stack[top_pos] << '\n';
}
