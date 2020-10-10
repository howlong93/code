#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int test_amount;
    cin >> test_amount;
    while (test_amount--) {
        int n, i, ans_x, ans_y;
        cin >> n;
        vector<int> x(n), y(n);
        long long int ans = 0;

        for (i = 0; i < n; i++) cin >> x[i] >> y[i];

        nth_element(x.begin(), x.begin() + n / 2, x.end());
        nth_element(y.begin(), y.begin() + n / 2, y.end());
        /*
                sort(x.begin(), x.end());
                sort(y.begin(), y.end());
        */
        ans_x = *(x.begin() + n / 2);
        ans_y = *(y.begin() + n / 2);

        //        cout << ans_x << ' ' << ans_y << "\n";

        for (auto k : x) ans += abs(ans_x - k);

        for (auto k : y) ans += abs(ans_y - k);

        cout << ans << "\n";
    }

    return 0;
}
