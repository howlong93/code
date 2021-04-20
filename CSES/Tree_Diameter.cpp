#include <bits/stdc++.h>

using namespace std;

struct Node {
	vector<int> c;
	int lnth = 0, hgt = 0;
};

vector<Node> tree;
vector<bool> vis;

int build_hgt (int x) {
	vis[x] = 1;

	int ans = 0;
	for (auto k: tree[x].c) {
		if (!vis[k]) {
			tree[k].hgt = build_hgt (k);
			ans = max (ans, tree[k].hgt+1);
		}
	}

	return ans;
}

int build_lnth (int x) {
	vis[x] = 1;

	int f = 0, s = 0;
	for (auto k: tree[x].c) {
		if (!vis[k]) {
			if (tree[k].hgt+1 > f) s = f, f = tree[k].hgt+1;
			else if (tree[k].hgt+1 <= f && tree[k].hgt+1 > s) s = tree[k].hgt+1;
			tree[k].lnth = build_lnth (k);
		}
	}

	return s+f;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	if (n == 1) {
		cout << 0 << '\n';
		return 0;
	}

	tree = vector<Node> (n+1);
	vis = vector<bool> (n+1, 0);

	for (int i = 0; i <= n-1; i++) {
		int p, q;
		cin >> p >> q;

		tree[p].c.emplace_back (q);
		tree[q].c.emplace_back (p);
	}

	tree[1].hgt = build_hgt (1);

	fill (vis.begin(), vis.end(), 0);
	tree[1].lnth = build_lnth (1);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max (ans, tree[i].lnth);
	}
	cout << ans << '\n';

	return 0;
}
