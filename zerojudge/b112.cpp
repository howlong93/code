#include <iostream>

using namespace std;

int gcd(int, int);

int main() {
    int amount, ans, man;

    while (cin >> amount) {
        int i = 0;
        if (amount == 1) {
            cin >> ans;
            cout << ans;
            continue;
        }

        cin >> ans >> man;
        ans = gcd(ans, man);

        for (i = 2; i < amount; i++) {
            cin >> man;
            ans = gcd(ans, man);
        }
        cout << ans << "\n";
    }

    return 0;
}

int gcd(int x, int y) {
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}
