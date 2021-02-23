#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
	int n;
	cin >> n;

	vector<vector<int>> dp = vector<vector<int>> (n+1, vector<int> (7, 0));

	for (int i = 1; i <= n && i <= 6; i++) dp[i][i] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i-j > 0) dp[i][j] = (dp[i][j] + dp[i-j][0]) % MOD;
		}

		for (int j = 1; j <= 6; j++)
			dp[i][0] = (dp[i][0] + dp[i][j]) % MOD;
	}

	cout << dp[n][0] << '\n';

	return 0;
}
