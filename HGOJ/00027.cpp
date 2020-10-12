#include <iostream>

using namespace std;

int main() {
    int n, ans = 0, s, cnt = 0;

    cin >> n;
    while (cnt < 3) {
        cin >> s;
        ans += s % n;
        cnt++;
    }

    cout << ans << "\n";
}
