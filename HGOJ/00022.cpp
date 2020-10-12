#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b);
unsigned long long int cnt = 0;

#define MAX 1005
int data[MAX] = {0};

int main() {
    int amount = 0, keep = 0;
    cin >> amount;

    for (int i = 0; i < amount; i++) {
        cin >> data[i];
    }

    sort(data, data + amount, cmp);

    std::cout << cnt;

    return 0;
}

bool cmp(int a, int b) {
    cnt++;
    return a < b;
}
