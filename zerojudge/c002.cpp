#include <iostream>

using namespace std;

int f91(int);

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        cout << "f91(" << n << ") = " << f91(n) << "\n";
        cin >> n;
    }

    return 0;
}

int f91(int x) {
    if (x <= 100)
        return f91(f91(x + 11));
    else
        return x - 10;
}
