#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        int ans = 0;
        for (int i = n - k + 1; i <= n; i++) {
            ans = (ans + m) % i;
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}
