#include <bits/stdc++.h>

using namespace std;

int stamp = 0;
vector<vector<int>> graph;
vector<int> vis, low, ap, ans;

void DFS (int x, int p) {
	low[x] = vis[x] = ++stamp;
	int child = 0;
	for (auto k: graph[x]) {
		if (!vis[k]) {
			child++;
			DFS (k, x);
			low[x] = min(low[x], low[k]);
			if (low[k] >= vis[x]) ap[x] = 1;
		}
		else if (vis[k] < vis[x] && k != p)
			low[x] = min (low[x], vis[k]);
	}
	if (p <= 1 && child <= 1) ap[x] = 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int qamt;
	cin >> qamt;

	int n, m;
	for (int cur_amt = 0; cur_amt < qamt; cur_amt++) {
		ans.clear();
		cin >> n >> m;

		graph = vector<vector<int>> (n+1);
		vis = low = ap = vector<int> (n+1, 0); 
		
		for (int i = 0; i < m; i++) {
			int pos, dest;
			cin >> pos >> dest;
			graph[pos].emplace_back (dest);
			graph[dest].emplace_back (pos);
		}

		DFS (1, 1);
		for (int i = 1; i <= n; i++) {
			if (ap[i]) ans.emplace_back(i);
		}

		if (!ans.size()) cout << 0 << '\n' << 0 << '\n';
		else {
			cout << ans.size() << '\n';
			for (auto k: ans) cout << k << ' ';
			cout << '\n';
		}
	}

	return 0;
}
