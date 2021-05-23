#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> ans, color;
vector<bool> vis;
map <int, int> temp;

void dfs (int x) {
	if (temp[color[x]] == 0) ans.emplace_back (x);
	temp[color[x]]++;
	vis[x] = true;

	for (auto k: tree[x]) {
		if (!vis[k]) {
			dfs (k);
		}
	}

	temp[color[x]]--;
}


int main() {
	int n;
	cin >> n;
	color = vector<int> (n+1);
	tree = vector<vector<int>> (n+1);
	vis = vector<bool> (n+1, false);

	for (int i = 1; i <= n; i++) cin >> color[i];

	for (int i = 0; i < n-1; i++) {
		int p, q;
		cin >> p >> q;
		tree[p].emplace_back (q);
		tree[q].emplace_back (p);
	}

	dfs (1);

	sort (ans.begin(), ans.end());

	for (auto k: ans) cout << k << '\n';

	return 0;
}
