#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, lim;
    cin >> n >> lim;
    vector<int> pr, pg;
    vector<vector<int> > dp = vector<vector<int> >(n, vector<int>(lim + 1, 0));

    pr = pg = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> pr[i];
    for (int i = 0; i < n; i++) cin >> pg[i];

    for (int i = pr[0]; i <= lim; i++) dp[0][i] = pg[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < pr[i]; j++) dp[i][j] = dp[i - 1][j];
        for (int j = pr[i]; j <= lim; j++) {
            dp[i][j] = max(dp[i - 1][j - pr[i]] + pg[i], dp[i - 1][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= lim; i++) {
        ans = max(ans, dp[n - 1][i]);
    }

    cout << ans << '\n';

    return 0;
}
