#include <iostream>

using namespace std;

int main() {
    bool flag = false;
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    if (a > 0)
        a = 1;
    else
        a = 0;

    if (b > 0)
        b = 1;
    else
        b = 0;

    if ((a & b) == c) {
        cout << "AND\n";
        flag = true;
    }
    if ((a | b) == c) {
        cout << "OR\n";
        flag = true;
    }
    if ((a ^ b) == c) {
        cout << "XOR\n";
        flag = true;
    }

    if (!flag) cout << "IMPOSSIBLE\n";

    return 0;
}
