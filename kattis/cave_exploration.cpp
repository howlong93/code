#include <bits/stdc++.h>

using namespace std;

int stamp = 0, ans = 0;
vector<vector<int>> graph, bridge;
vector<int> low, vis;

void DFS (int x, int p) {
	low[x] = vis[x] = ++stamp;
	int child = 0;
	for (size_t i = 0; i < graph[x].size(); i++) {
		int k = graph[x][i];
		if (!vis[k]) {
			child++;
			DFS (k, x);
			low[x] = min (low[x], low[k]);
			if (low[k] > vis[x]) {
				bridge[x][i] = 1;
				graph[x][i] = -1;
			}
		}
		else if (vis[k] < vis[x] && k != p) {
			low[x] = min (low[x], vis[k]);
		}
	}
}

void find_ans (int x) {
	ans++;
	vis[x] = 1;
	for (auto k: graph[x]) {
		if (k != -1 && !vis[k]) {
			find_ans (k);
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	graph = vector<vector<int>> (n);
	bridge = vector<vector<int>> (n, vector<int> (n, 0));
	low = vis = vector<int> (n, 0);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	DFS (0, 0);
	vis = vector<int> (n, 0);

	find_ans(0);
	cout << ans << '\n';

	return 0;
}
