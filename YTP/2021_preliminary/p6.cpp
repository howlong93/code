#include <bits/stdc++.h>

using namespace std;

struct Node {
	int prc, wght;
};

int main() {
	int n, m, c, cur = 1;
	cin >> n >> m >> c;
	vector<Node> dat (n+1);
	
	for (int i = 1; i <= n; i++) cin >> dat[i].prc;
	for (int i = 1; i <= n; i++) cin >> dat[i].wght;
	
	vector<int> disc(m+1), nind(n+1, -1), sz(m+1, 0), psum(m+1, 0), wsum(m+1, 0);

	for (int i = 1; i <= m; i++) cin >> disc[i];
	for (int i = 1; i <= m; i++) cin >> sz[i];

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < sz[i]; j++) {
			int tmp;
			cin >> tmp;
			nind[tmp] = cur++;
			psum[i] += dat[tmp].prc;
			wsum[i] += dat[tmp].wght;
		}
		psum[i] -= disc[i];
		if (i > 0) sz[i] += sz[i-1];
	}
	for (int i = 1; i <= n; i++)
		if (nind[i] == -1) nind[i] = cur++;
	
	vector<Node> plate(n+1);
	for (int i = 1; i <= n; i++) plate[nind[i]] = dat[i];

	int ans = 0;
	cur = 1;
	vector<vector<int>> dp = vector<vector<int>> (n+1, vector<int> (c+1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= c; j++) {
			dp[i][j] = dp[i-1][j];
			if (j-plate[i].prc >= 0) {
				dp[i][j] = max (dp[i][j], dp[i-1][j-plate[i].prc] + plate[i].wght);
			}
			if (i == sz[cur] && j-psum[cur] >= 0) {
				dp[i][j] = max (dp[i][j], dp[i-sz[cur]+sz[cur-1]][j-psum[cur]] + wsum[cur]);
			}
			ans = max (ans, dp[i][j]);
		}
		if (sz[cur] == i) cur++;
	}

	cout << ans << '\n';

	return 0;
}
