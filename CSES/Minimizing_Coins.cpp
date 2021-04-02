#include <bits/stdc++.h>

using namespace std;

vector<int> coin, dp;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, tar;
	cin >> n >> tar;

	coin = vector<int> (n);
	dp = vector<int> (tar+1, INT_MAX -1);
	dp[0] = 0;

	for (int i = 0; i < n; i++) cin >> coin[i];
	for (int i = 0; i < n; i++)
		if (coin[i] <= tar) dp[coin[i]] = 1;

	for (int i = 1; i <= tar; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coin[j] >= 0) {
				dp[i] = min (dp[i-coin[j]] + 1, dp[i]);
			}
		}
	}
	
	if (dp[tar] == INT_MAX-1) cout << -1 << '\n';
	else cout << dp[tar] << '\n';

	return 0;
}
