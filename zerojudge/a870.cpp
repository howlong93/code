#include <bits/stdc++.h>

using namespace std;

struct _Node {
    _Node *next = nullptr, *prev = nullptr;
    string data;
};

_Node *front = nullptr, *last = nullptr;

void add(string build) {
    _Node *cur = new (_Node);
    if (front == nullptr) {
        front = last = cur;
        cur->data = build;
    } else {
        cur->prev = last;
        last->next = cur;
        last = cur;
        cur->data = build;
    }
}

void insert(string build, string data) {
    _Node *cur = new (_Node), *dest = front;
    cur->data = build;

    while (dest != nullptr && dest->data != data) {
        dest = dest->next;
    }

    cur->next = dest;
    if (dest->prev != nullptr) {
        cur->prev = dest->prev;
        dest->prev->next = cur;
    } else
        front = cur;

    dest->prev = cur;
}

void remove(string undo) {
    _Node *dest = front;
    while (dest->data != undo) dest = dest->next;

    if (dest == front) {
        if (dest->next != nullptr) {
            dest->next->prev = nullptr;
            front = dest->next;
        } else {
            front = last = nullptr;
        }
    } else if (dest == last) {
        last = dest->prev;
        dest->prev->next = nullptr;
    } else {
        dest->next->prev = dest->prev;
        dest->prev->next = dest->next;
    }
    delete dest;
}

int main() {
    string choice, input, data;

    cin >> choice;
    while (choice != "SHOW") {
        if (choice == "ADD") {
            cin >> input;
            add(input);
        } else if (choice == "INSERT") {
            cin >> input >> data;
            insert(input, data);
        } else if (choice == "REMOVE") {
            cin >> input;
            remove(input);
        }
        cin >> choice;
    }

    _Node *cur = front;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
    return 0;
}
