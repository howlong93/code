#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<char>> input = vector<vector<char>> (n+2, vector<char> (n+2, '*'));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input[i][j];
		}
	}

	vector<vector<long long>> dp = vector<vector<long long>> (n+2, vector<long long> (n+2, 0));
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (input[i][j-1] == '.') dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
			if (input[i-1][j] == '.') dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
			if (input[i][j] == '*') dp[i][j] = 0;
		}
	}

	cout << dp[n][n] << '\n';

	return 0;
}
