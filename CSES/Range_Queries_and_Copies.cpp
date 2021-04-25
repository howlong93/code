#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
	long long val;
	int l, r;
	struct segment_tree *lc, *rc;
};

segment_tree* build (int L, int R) {
	segment_tree *node = new (segment_tree);
	node -> l = L, node -> r = R;

	if (L == R) {
		cin >> node -> val;
		return node;
	}

	int mid = (L+R)/2;
	node -> lc = build (L, mid);
	node -> rc = build (mid+1, R);

	node -> val = node -> lc -> val + node -> rc -> val;
	return node;
}

segment_tree* update (long long x, int pos, segment_tree *_node) {
	segment_tree *node = new segment_tree;

	*node = *_node;
	if (node -> l == node -> r && node -> l == pos) {
		node -> val = x;
		return node;
	}

	if (pos < node -> rc ->	l) node -> lc = update (x, pos, node -> lc);
	else node -> rc = update (x, pos, node -> rc);

	node -> val = node -> lc -> val + node -> rc -> val;

	return node;
}

long long query (int L, int R, segment_tree *node) {
	if (node -> l > R || node -> r < L) return 0;
	if (node -> l >= L && node -> r <= R) return node -> val;

	return query (L, R, node -> lc) + query (L, R, node -> rc);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<segment_tree*> roots;
	roots.push_back (nullptr);
	roots.push_back (build (1, n));

	for (int i = 0; i < m; i++) {
		int opt;
		cin >> opt;

		if (opt == 1) {
			int k, a, x;
			cin >> k >> a >> x;
			roots[k] = update (x, a, roots[k]);
		}
		else if (opt == 2) {
			int k, a, b;
			cin >> k >> a >> b;

			cout << query (a, b, roots[k]) << '\n';
		}
		else if (opt == 3) {
			int k;
			cin >> k;

			roots.push_back (roots[k]);
		}
	}

	return 0;
}
