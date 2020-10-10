#include <iostream>

using namespace std;

int main() {
    int n = 0, cnt = 1;
    cin >> n;

    while (n >= 0) {
        int multi = 1, ans;

        for (ans = 0; multi < n; ans++) multi *= 2;

        cout << "Case " << cnt << ": " << ans << "\n";
        cin >> n;
        cnt++;
    }

    return 0;
}
