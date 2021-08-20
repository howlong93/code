#include <bits/stdc++.h>

using namespace std;

vector<bitset<50005>> S;
vector<vector<int>> graph;
vector<bool> vis;

void dfs (int x) {
	vis[x] = true;
	S[x][x] = 1;
	for (auto k: graph[x]) {
		if (!vis[k]) dfs (k);
	   	S[x] |= S[k];
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	graph.resize(n+1);

	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;

		graph[p].emplace_back (q);
	}
	
	S = vector<bitset<50005>> (n+1);
	vis = vector<bool> (n+1, 0);

	dfs (1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs (i);
	}
	for (int i = 1; i <= n; i++) cout << S[i].count() << ' ';
	cout << '\n';

	return 0;
}
