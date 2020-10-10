#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int guard[4] = {}, n, i, a, b, ans;

    cin >> guard[0] >> guard[1] >> guard[2] >> guard[3] >> n;

    vector<pair<int, int>> city(n);

    for (i = 0; i < n; i++) {
        cin >> a >> b;
        city[i].first =
            (a - guard[0]) * (a - guard[0]) + (b - guard[1]) * (b - guard[1]);
        city[i].second =
            (a - guard[2]) * (a - guard[2]) + (b - guard[3]) * (b - guard[3]);
    }

    sort(city.begin(), city.end(), [](pair<int, int> &k, pair<int, int> &l) {
        return k.first < l.first;
    });

    for (i = n - 2; i >= 0; i--) {
        city[i].second = max(city[i + 1].second, city[i].second);
    }

    ans = min(city[0].second, city[n - 1].first);
    for (i = 0; i < n - 1; i++) {
        ans = min(city[i].first + city[i + 1].second, ans);
    }

    cout << ans << "\n";

    return 0;
}
