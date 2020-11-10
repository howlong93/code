#include <bits/stdc++.h>

using namespace std;

int stamp;
vector<vector<int>> graph, bridge;
vector<pair<int, int>> ans;
vector<int> vis, low;

void DFS (int x, int p) {
	low[x] = vis[x] = ++stamp;
	int child = 0;
	for (size_t i = 0; i < graph[x].size(); i++) {
		int k = graph[x][i];
		if (!vis[k]) {
			ans.emplace_back (make_pair (x, k));
			child++;
			DFS (k, x);
			low[x] = min(low[x], low[k]);
			if (low[k] > vis[x]) {
				bridge[x][i] = 1;
				ans.emplace_back (make_pair (k, x));
			}
		}
		else if (vis[k] < vis[x] && k != p) {
			ans.emplace_back (make_pair (x, k));
			low[x] = min (low[x], vis[k]);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m, cur_q = 1;
	while (cin >> n >> m && !(n == 0 && m == 0)) {
		ans.clear();
		stamp = 0;
		graph = vector<vector<int>> (n+1);
		bridge = vector<vector<int>> (n+1, vector<int> (m+1, 0));
		vis = low = vector<int> (n+1);
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].emplace_back (b);
			graph[b].emplace_back (a);
		}

		DFS (1, 1);
		
		sort (ans.begin(), ans.end());
		cout << cur_q++ << "\n\n";
		for (auto k: ans) {
			cout << k.first << ' ' << k.second << '\n';
		}
		cout << "#\n";
	}

	return 0;
}
