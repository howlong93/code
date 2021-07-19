#include <bits/stdc++.h>

using namespace std;

vector<int> color;
vector<vector<int>> tree;

void dfs (int x, int col);

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, query;
	cin >> n >> query;
	color = vector<int> (n+1, -1);
	tree = vector<vector<int>> (n+1);
	
	for (int i = 1; i < n; i++) {
		int p, q;
		cin >> p >> q;
		
		tree[p].push_back (q);
		tree[q].push_back (p);
	}
	
	dfs (1, 0);
	for (int i = 0; i < query; i++) {
		int p, q;
		cin >> p >> q;
		
		cout << (color[p] == color[q] ? "Town\n" : "Road\n");
	}
	
	return 0;
}

void dfs (int x, int col) {
	color[x] = col;
	for (auto k: tree[x]) {
		if (color[k] == -1) dfs (k, col^1);
	}
}
