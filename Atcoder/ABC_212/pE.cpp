#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main() {
	const long long mod = 998244353;
	int n, m ,k;
	cin >> n >> m >> k;
	
	vector<pair<int, int>> graph(m);

	for (int i = 0; i < m; i++) cin >> graph[i].x >> graph[i].y;
	
	vector<vector<long long>> ans = vector<vector<long long>> (n+1, vector<long long> (k+1, 0));
	ans[1][0] = 1;
	long long sum = 1;
	
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) ans[j][i] = (sum - ans[j][i-1] + mod) % mod;
		for (int j = 0; j < m; j++) {
			int p = graph[j].x, q = graph[j].y;
			ans[p][i] = (ans[p][i] - ans[q][i-1] + mod) % mod;
			ans[q][i] = (ans[q][i] - ans[p][i-1] + mod) % mod;
		}
		
		sum = 0;
		for (int j = 1; j <= n; j++) sum = (sum + ans[j][i]) % mod;
	}
	
	cout << ans[1][k] << '\n';
	
	return 0;
}
