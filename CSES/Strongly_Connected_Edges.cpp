#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second

vector<vector<pii>> graph, rev;
vector<pii> edge;
bitset<100005> vis;
bitset<200005> vis_edge;

void dfs (int x) {
	vis[x] = 1;
	for (auto k: graph[x]) {
		if (!vis_edge[k.y]) edge[k.y].x = x, edge[k.y].y = k.x;
		if (!vis[k.x]) dfs (k.x);
	}
}

void check_for (int x) {
	vis[x] = 1;
	for (auto k: graph[x])
		if (!vis[k.x]) check_for(k.x);
}

void check_rev (int x) {
	vis[x] = 1;
	for (auto k: rev[x])
		if (!vis[k.x]) check_rev (k.x);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	vis.reset();
	vis_edge.reset();
	
	int n, m;
	cin >> n >> m;

	graph.resize(n+1);
	edge.resize(m);
	
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		graph[p].push_back ({q, i});
		graph[q].push_back ({p, i});
	}
	
	dfs (1);
	
	graph = vector<vector<pii>> (n+1);
	rev = vector<vector<pii>> (n+1);
	
	for (int i = 0; i < m; i++) {
		pii tmp = edge[i];
		graph[tmp.x].push_back ({tmp.y, i});
		rev[tmp.y].push_back ({tmp.x, i});
	}
	
	vis.reset();
	check_for (1);
	if (vis.count() != n) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	
	vis.reset();
	check_rev (1);
	if (vis.count() != n) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	
	for (auto k: edge) cout << k.x << ' ' << k.y << '\n';
	
	return 0;
}
