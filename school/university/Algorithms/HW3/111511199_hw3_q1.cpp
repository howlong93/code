#include <bits/stdc++.h>

using namespace std;

int val (const vector<vector<int>> &dp, int i, int j) {
	if (i < 0 || j < 0) return INT_MAX;
	return dp[i][j];
}

int main() {
	int row, col;
	cin >> row >> col;

	vector<vector<int>> graph, dp;
	graph = dp = vector<vector<int>> (row, vector<int> (col, 0));

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> graph[i][j];

	dp[0][0] = graph[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == 0 && j == 0) continue;
			int up = val (dp, i-1, j);
			int left = val (dp, i, j-1);
			dp[i][j] = min (up, left) + graph[i][j];
		}
	}

	cout << dp[row-1][col-1] << '\n';

	return 0;
}
