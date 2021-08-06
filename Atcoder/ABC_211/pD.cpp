#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	const int INF = 1e9+7;
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph = vector<vector<int>> (n+1);
	vector<ll> cnt, vis;
	cnt = vis = vector<ll> (n+1, 0);
	for (int i = 2; i <= n; i++) vis[i] = INF;
	cnt[1] = 1;
	
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		graph[p].emplace_back (q);
		graph[q].emplace_back (p);
	}
	
	queue<int> que;
	que.push(1);
	while (que.size()) {
		ll tmp = que.front();
		que.pop();
		for (auto k: graph[tmp]) {
			if (vis[tmp] < vis[k]) {
				if (cnt[k] == 0) que.push(k);
				vis[k] = vis[tmp]+1;
				cnt[k] = (cnt[k] + cnt[tmp]) % INF;
			}
		}
	}
	
	cout << cnt[n] << '\n';
	
	return 0;
}
