#include <bits/stdc++.h>

using namespace std;

struct Node {
	vector<int> c;
	int s = 0;
};

vector<Node> tree;

int dfs (int x) {
	int ans = 0;
	for (auto k: tree[x].c) {
		tree[k].s = dfs (k);
		ans += tree[k].s+1;
	}
	
	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	tree = vector<Node> (n+1);

	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		tree[p].c.emplace_back (i);
	}

	tree[1].s = dfs (1);

	for (int i = 1; i <= n; i++) cout << tree[i].s << ' ';
	cout << '\n';

	return 0;
}
