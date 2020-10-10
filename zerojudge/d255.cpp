#include <iostream>

using namespace std;

int gcd(int x, int y);

int main() {
    int n = 0, i, j;
    cin >> n;

    while (n > 0) {
        int ans = 0;
        for (i = 1; i < n; i++)
            for (j = i + 1; j <= n; j++) ans += gcd(i, j);

        cout << ans << "\n";
        cin >> n;
    }

    return 0;
}

int gcd(int x, int y) {
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}
