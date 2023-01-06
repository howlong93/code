#include <bits/stdc++.h>

using namespace std;

int adj[105][105] = {0};
int deg[105] = {0};
int max_node = 0, chromatic_num = 0;

vector<int> graph[105], ver_of_col[105];
bool change (int col, vector<int> &temp) {
	for (auto k: ver_of_col[col]) {
		bool oper = false;
		for (int i = 0; i < chromatic_num; i++) {
			if (i == col) continue;
			bool valid = true;
			for (int j = 0; j <= max_node; j++) {
				if (adj[k][j] && temp[j] == i) {
					valid = false;
					break;
				}
			}
			if (valid) {
				oper = true;
				temp[k] = i;
			}
		}
		if (!oper) return false;
	}
	return true;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int u, v;
	
	while (cin >> u >> v) {
		adj[u][v] = 1, adj[v][u] = 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
		max_node = max ({max_node, u, v});

		deg[u]++, deg[v]++;
	}

	vector<int> color = vector<int> (max_node+1, -1), nodes = vector<int> (max_node+1, 0);
	vector<bool> valid = vector<bool> (max_node+1, 0);

	for (int i = 0; i <= max_node; i++) nodes[i] = i;
	sort (nodes.begin(), nodes.end(), [] (int &a, int &b) {
			return deg[a] > deg[b];
		});

	for (int m = 0; m <= max_node; m++) {
		int i = nodes[m];
		for (auto k: graph[i]) {
			if (color[k] != -1) valid[color[k]] = true;
		}

		int cur = 0;
		for (cur = 0; cur <= max_node; cur++) {
			if (valid[cur] == false) break;
		}

		color[i] = cur;
		chromatic_num = max (chromatic_num, cur+1);

		for (auto k : graph[i]) {
			if (color[k] != -1) valid[color[k]] = false;
		}
	}
	
	vector<int> temp;


	while (1) {
		bool changed = false;
		for (int i = 0; i <= max_node; i++) ver_of_col[color[i]].push_back (i);

		for (int i = 0; i < chromatic_num; i++) {
			temp = color;
			if (change(i, temp)) {
				changed = true;
				color = temp;
				chromatic_num--;
			}
		}
		if (!changed) break;
	}
	cout << chromatic_num << '\n';

	return 0;
}
