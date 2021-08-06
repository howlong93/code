#include <bits/stdc++.h>

using namespace std;

int main() {
	const long long INF = 2147483648;
	long long h, w, c;
	long long output = LONG_LONG_MAX;
	cin >> h >> w >> c;
	
	vector<vector<long long>> grid, dp, ans;
	grid = dp = ans = vector<vector<long long>> (h+1, vector<long long> (w+1, 0));

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) cin >> grid[i][j];
	}
	
	for (int i = 0; i <= h; i++) dp[i][0] = INF;
	for (int j = 0; j <= w; j++) dp[0][j] = INF;
	
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			dp[i][j] = min ({grid[i][j], dp[i-1][j] + c, dp[i][j-1] + c});
			
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			ans[i][j] = min (dp[i][j-1], dp[i-1][j]) + c + grid[i][j];
			output = min (output, ans[i][j]);
		}
	}
	
	cout << output << '\n';
	
	return 0;
}
