#include <bits/stdc++.h>

using namespace std;

#define vb vector<bool>
#define vi vector<int>

vector<vb> vis;
vector<vi> graph;

bool check (int x, int y) {
	if (x < 0 || y < 0 || x >= graph.size() || y >= graph[0].size()) return true;
	if (!graph[x][y]) return true;
	return vis[x][y];
}
	
void dfs (int x, int y) {
	if (check (x, y)) return;
	
	vis[x][y] = true;
	dfs (x+1, y);
	dfs (x-1, y);
	dfs (x, y+1);
	dfs (x, y-1);
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vis = vector<vb> (n, vb (m, 0));
	graph = vector<vi> (n, vi (m, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			
			if (c == '#') graph[i][j] = 0;
			if (c == '.') graph[i][j] = 1;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] && !vis[i][j]) ans++, dfs (i, j);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
