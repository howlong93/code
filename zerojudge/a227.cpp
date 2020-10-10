#include <iostream>

using namespace std;

void recur(int, int, int, int);

int main() {
    int n = 0;

    while (cin >> n) {
        recur(n, 0, 1, 2);
        cout << "\n";
    }

    return 0;
}

void recur(int n, int a, int b, int c) {
    if (n == 0) return;

    recur(n - 1, a, c, b);
    cout << "Move ring " << n << " from " << char('A' + a) << " to "
         << char('A' + c) << "\n";
    recur(n - 1, b, a, c);
}
