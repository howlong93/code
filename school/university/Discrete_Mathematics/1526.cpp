#include <bits/stdc++.h>

using namespace std;

struct Node {
	int record[105] = {0};
	int cnt = 0;
};

int max_node = 0, min_node = 120;
vector<vector<int>> ans;
int adj[105][105] = {0};

Node inter(Node x, int v) {
	for (int i = min_node; i <= max_node; i++) {
		if (x.record[i] && !adj[i][v]) {
			x.record[i] = 0;
			x.cnt--;
		}
	}
	return x;
}

void recur (int lev, Node r, Node p, Node x) {
	if (!p.cnt && !x.cnt) {
		vector<int> temp;
		for (int i = min_node; i <= max_node; i++) {
			if (r.record[i]) temp.push_back (i);
		}
		ans.push_back (temp);
		return;
	}

	int pivot = min_node;
	for (pivot = min_node; pivot <= max_node; pivot++) {
		if (p.record[pivot] || x.record[pivot]) break;
	}

	for (int i = min_node; i <= max_node; i++) {
		if (p.record[i] && !adj[i][pivot]) {
			r.record[i] = 1, r.cnt++;
			recur (lev+1, r, inter(p,i), inter(x,i));
			r.record[i] = 0, r.cnt--;
			p.record[i] = 0, p.cnt--;
			if (!x.record[i]) x.record[i] = 1, x.cnt++;
		}
	}

	return;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int u, v;
	while (cin >> u >> v) {
		adj[u][v] = 1, adj[v][u] = 1;
		min_node = min ({min_node, u, v});
		max_node = max ({max_node, u, v});
	}

	Node r, p, x;

	for (int i = min_node; i <= max_node; i++) {
		r.record[i] = x.record[i] = 0;
		p.record[i] = 1;
	}
	p.cnt = max_node - min_node + 1;
	r.cnt = x.cnt = 0;

	recur (0, r, p, x);

	for (size_t i = 0; i < ans.size(); i++) sort (ans[i].begin(), ans[i].end());

	sort (ans.begin(), ans.end(), [] (vector<int> &a, vector<int> &b) {
		    if (a.size() != b.size()) return a.size() < b.size();
			return a < b;
        });

	size_t cur_size = 0;
	for (size_t i = 0; i < ans.size(); i++) {
		if (ans[i].size() != cur_size)
			cout << ans[i].size() << '\n', cur_size = ans[i].size();

		cout << "{";
		for (size_t j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << (j == ans[i].size()-1 ? "}\n" : ",");
	}

	return 0;
}
