#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int v, next;
};

vector<int> head, d;
int cnt;
vector<vector<int>> table;
vector<Edge> edge;

void init (int n) {
	head = vector<int> (n+1, 0);
	d = vector<int> (n+1, 0);
	table = vector<vector<int>> (n+1, vector<int> (21, 0));
}

void addedge (int u, int v) {
	edge.push_back ( {v, head[u]} );
	head[u] = edge.size()-1;
}

void dfs (int u, int fa) {
	d[u] = d[fa]+1;
	table[u][0] = fa;

	for (int i = 1; (1 << i) <= d[u]; i++) {
		table[u][i] = table[table[u][i-1]][i-1];
	}

	for (int i = head[u]; i; i = edge[i].next) {
		if (edge[i].v != fa) dfs (edge[i].v, u);
	}
}

int lca (int a, int b) {
	if (d[a] > d[b]) swap (a, b);

	for (int i = 20; i >= 0; i--) {
		if (d[a] <= d[b] - (1 << i))
			b = table[b][i];
	}
	if (a == b) return a;

	for (int i = 20; i >= 0; i--) {
		if (table[a][i] == table[b][i]) continue;
		a = table[a][i], b = table[b][i];
	}
	return table[a][0];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	init (n);
	addedge (0, 0);
	for (int i = 1; i < n; i++) {
		int ta, tb;
		cin >> ta >> tb;

		addedge (ta, tb);
		addedge (tb, ta);
	}

	dfs (1, 0);
	
	for (int i = 1; i <= m; i++) {
		int ta, tb;
		cin >> ta >> tb;

		cout << (lca (ta, tb)) << '\n';
	}

	return 0;
}
