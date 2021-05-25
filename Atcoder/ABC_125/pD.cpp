#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> num = vector<long long> (n);
	vector<vector<long long>> dp = vector<vector<long long>> (n, vector<long long> (2, 0));

	for (int i = 0; i < n; i++) cin >> num[i];

	dp[0][0] = num[0], dp[0][1] = num[0]*-1;
	for (int i = 1; i < n-1; i++) {
		dp[i][0] = max (dp[i-1][1] + (-1)*num[i], dp[i-1][0] + num[i]);
		dp[i][1] = max (dp[i-1][1] + num[i], dp[i-1][0] + (-1)*num[i]);
	}

	cout << max (dp[n-2][0] + num[n-1], dp[n-2][1] - num[n-1]) << '\n';

	return 0;
}
