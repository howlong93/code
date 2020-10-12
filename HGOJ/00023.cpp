#include <iostream>

using namespace std;

void recursive(int, int, int, int);
int cnt = 0;

int main() {
    int n = 0;
    cin >> n;

    recursive(n, 1, 2, 3);
    cout << "total move: " << cnt;
}

void recursive(int n, int a, int b, int c) {
    if (n == 0) return;

    recursive(n - 1, a, c, b);
    cout << n << " from " << a << " to " << c << "\n";
    cnt++;
    recursive(n - 1, b, a, c);
}
