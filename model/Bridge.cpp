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

	int n, m;

	//TODO
	
	return 0;
}
