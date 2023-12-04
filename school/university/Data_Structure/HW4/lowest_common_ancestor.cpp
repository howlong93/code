#include <bits/stdc++.h>

using namespace std;

int traverse (int, int, int);

vector<vector<int>> adj_list;
vector<int> vis;
int common;

int main() {
	int n, q, s, r, c;
	cin >> n >> q >> s >> r;

	adj_list = vector<vector<int>> (n+1);
	vis = vector<int> (n+1, 0);

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;

		adj_list[a].push_back (b);
		adj_list[b].push_back (a);
	}

	while (q--) {
		cin >> c;
		common = c;

		traverse (c, s, r);
		cout << common << '\n';
		for (auto &k : vis) k = 0;
	}

	return 0;
}

int traverse (int cur, int s, int r) {
	vis[cur] = 1;
	int fnd = 0, total = 0;

	if (cur == s && cur == r) {
		common = cur;
		return 11;
	}
	else if (cur == s) {
		total = 10;
	}
	else if (cur == r) {
		total = 1;
	}

	for (auto k: adj_list[cur]) {
		if (!vis[k]) {
			fnd = traverse (k, s, r);
			if (fnd == 11) return 11;
			total += fnd;
		}
		if (total == 11) {
			common = cur;
			return 11;
		}
	}

	return total;
}
