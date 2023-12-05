#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	const int mod = 1e9+7;
	vector<long long> dp (n+1), keep (n+1);

	dp[0] = keep[0] = 0;
	dp[1] = 1, keep[1] = 0;
	if (n > 1) dp[2] = 2, keep[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = (2*keep[i-1] + dp[i-1] + dp[i-2])%mod;
		keep[i] = (dp[i-2] + keep[i-1])%mod;
	}

	cout << dp[n]%mod << '\n';

	return 0;
}
