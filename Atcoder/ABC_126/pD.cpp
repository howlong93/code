#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second
vector<vector<pii>> tree;
vector<bool> vis, col;

void dfs (int u) {
	vis[u] = true;
	for (auto k: tree[u]) {
		if (!vis[k.x]) {
			if (k.y % 2) col[k.x] = col[u] ^ 1;
			else col[k.x] = col[u];
			dfs (k.x);
		}
	}
}	

int main() {
	int n;
	cin >> n;

	tree = vector<vector<pii>> (n+1);
	vis = col = vector<bool> (n+1, 0);
	
	for (int i = 0; i < n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		tree[v].push_back ({u, w});
		tree[u].push_back ({v, w});
	}
	
	col[1] = 0;
	dfs (1);
	for (size_t i = 1; i < col.size(); i++) cout << col[i] << '\n';

	return 0;
}
