#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int amt, window;
    cin >> amt;

    for (int i = 0; i < amt; i++) {
        int a, b, c;
        bool flag = false;
        cin >> window;

        for (a = 0; a <= window; a += 7) {
            for (b = 0; a + b <= window; b += 5) {
                for (c = 0; a + b + c <= window; c += 3) {
                    if (a + b + c == window) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }

        if (flag)
            cout << c / 3 << ' ' << b / 5 << ' ' << a / 7 << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}
