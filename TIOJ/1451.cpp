#include <bits/stdc++.h>

using namespace std;

#define iv vector<int>
#define bv vector<bool>

vector<iv> rev, graph, scc;
iv W;
bv vis;
int cnt = 0;

void dfs1 (int x) {
	vis[x] = true;
	for (auto k: graph[x])
		if (!vis[k]) dfs1 (k);

	W.emplace_back (x);
}

void dfs2 (int x) {
	vis[x] = true;
	scc[cnt].emplace_back (x);
	
	for (auto k: graph[x])
		if (!vis[k]) dfs2 (k);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	rev = graph = scc = vector<iv> (n+1);
	vis = bv (n+1, 0);
	
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		
		graph[p].emplace_back (q);
		rev[q].emplace_back (p);
	}
	
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs1(i);
		
	fill (vis.begin(), vis.end(), 0);
	reverse (W.begin(), W.end());
	
	for (auto i: W)
		if (!vis[i]) dfs2(i), cnt++;

	cout << cnt << '\n';
	
	return 0;
}
