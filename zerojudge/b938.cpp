#include <bits/stdc++.h>

using namespace std;

bool killed[1000005] = {false};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n = 0, m = 0, end, target;

    cin >> n >> m;

    end = n;

    while (m--) {
        cin >> target;

        if (target == end || killed[target]) {
            cout << "0u0 ...... ?\n";
        } else {
            int ans = target + 1;
            while (killed[ans]) {
                ans++;
            }

            cout << ans << "\n";
            killed[ans] = true;

            if (ans == end) {
                end = target;
            }
        }
    }

    return 0;
}
