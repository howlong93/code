#include <iostream>

using namespace std;

int main() {
    bool a, b;
    int m, n;

    cin >> m >> n;
    a = m % 2;
    b = n % 2;

    if (a ^ b)
        cout << "DIFFERENT";
    else
        cout << "SAME";

    return 0;
}
