#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	const int mod = 1e9+7;
	
	cin >> n;
	
	vector<int> num = vector<int> (n+1, 0);
	vector<vector<long long>> dp = vector<vector<long long>> (n+1, vector<long long> (n+1, 0));

	
	for (int i = 1; i <= n; i++) cin >> num[i];
	
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (num[i] < num[i-1]) dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % mod;
			else if (num[i] == num[i-1]) dp[i][j] = (dp[i][j-1] + dp[i-1][i-1]) % mod;
			else if (num[i] > num[i-1]) dp[i][j] = (dp[i][j-1] + dp[i-1][i-1]-dp[i-1][j-1] + mod) % mod;
		}
	}
	
	cout << dp[n][n] << '\n';
	
	return 0;
}
