#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, target;
	cin >> n >> target;

	vector<int> nums = vector<int> (n);
	vector<int> dp = vector<int> (target+1, 0);

	for (int i = 0; i < n; i++) cin >> nums[i];
	for (int i = 0; i < n; i++)
		if (nums[i] <= target) dp[nums[i]] = 1;

	for (int i = 1; i <= target; i++) {
		for (int j = 0; j < n; j++) {
			if (i-nums[j] > 0) {
				dp[i] = (dp[i] + dp[i-nums[j]]) % MOD;
			}
		}
	}

	cout << dp[target] << '\n';

	return 0;
}
