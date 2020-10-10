#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, i;
    cin >> n;

    while (n > 0) {
        map<long long int, int> data;
        int ans = 0, cur = 0;

        for (int counting = 0; counting < n; counting++) {
            int keep[5];
            long long int pre = 0;
            for (i = 0; i < 5; i++) cin >> keep[i];

            sort(keep, keep + 5);

            for (i = 0; i < 5; i++) pre = pre * 1000 + keep[i];

            data[pre]++;
        }

        for (auto k : data) {
            if (k.second > cur) {
                ans = k.second;
                cur = k.second;
            } else if (k.second == cur) {
                ans += cur;
            }
        }

        cout << ans << "\n";
        cin >> n;
    }

    return 0;
}
