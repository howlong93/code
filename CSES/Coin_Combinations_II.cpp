#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, target;
	cin >> n >> target;

	vector<int> nums (n+1);
	vector<vector<int>> dp = vector<vector<int>> (n+1, vector<int> (target+1, 0));
	for (int i = 1; i <= n; i++) cin >> nums[i];

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= target; j++) {
			dp[i][j] = dp[i-1][j];
			if (j - nums[i] >= 0) {
				dp[i][j] = (dp[i][j] + dp[i][j-nums[i]]) % MOD;
			}
		}
	}

	cout << dp[n][target] << '\n';
	return 0;
}
