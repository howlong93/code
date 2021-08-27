#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second

vector<vector<pii>> graph;
vector<pii> edge;
vector<bool> vis;
vector<bool> vis_edge;

void dfs (int x) {
	vis[x] = 1;
	for (auto k: graph[x]) {
		if (!vis[k.x]) {
			edge[k.y].x = x, edge[k.y].y = k.x;
			vis_edge[k.y] = 1;
			dfs (k.x);
		}
		else if (!vis_edge[k.y]) vis_edge[k.y] = 1, edge[k.y].x = k.x, edge[k.y].y = x;
	}
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	
	graph = vector<vector<pii>> (n+1);
	edge = vector<pii> (m);
	vis = vector<bool> (n+1, 0);
	vis_edge = vector<bool> (m, 0);
	
	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		graph[p].push_back({q, i});
		graph[q].push_back({p, i});
		edge[i].x = p, edge[i].y = q;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs (i);
	}
	
	for (int i = 0; i < m; i++) cout << edge[i].x << ' ' << edge[i].y << '\n';
	
	return 0;
}
