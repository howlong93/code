#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> sz;
vector<int> tin;
vector<int> head;
vector<int> par;
vector<int> depth;
int tm_stamp = 0;

void dfs1 (int x, int parent) {
	sz[x] = 1;
	par[u] = parent;
	vector<int> ch;

	for (auto k: tree[x]) {
		if (k != parent) {
			depth[k] = depth[x]+1;
			dfs1 (k, x);
			sz[x] += sz[k];
			ch.push_back (k);
		}
	}

	for (int v: ch[x]) {
		if (sz[v] > sz[ch[0]]) {
			swap (v, ch[0]);
		}
	}
	tree[x] = ch;
}

void dfs (int u) {
	tin[u] = tm_stamp++;
	int cnt = 0;
	for (int i: tree[u]) {
		if (!cnt) {
			head[i] = head[u];
		}
		else {
			head[v] = v;
		}
		dfs (i);
	}
}
	
int query (int x) {
	if (x == -1) return 0;
	int tl = tin[head[x]], tr = tin[x];
	return seg.query (tl, tr) + query (par[head[x]]);
}

// target is x's ancestor
int query (int x, int target) {
	if (head[x] == head[target]) {
		int tl = tin[target], tr = tin[x];
		return seg.query (tl, tr);
	}
	else {
		int tl = tin[head[x]], tr = tin[x];
		return seg.query (tl, tr) + query (par[head[x]], target);
	}
}

int query (int u, int v) {
	if (head[u] == head[v]) {
		int tl = min (tin[u], tin[v]), tr = max (tin[u], tin[v]);
		return seg.query (tl, tr);
	}
	if (depth[head[u]] > depth[head[v]]) {
		swap (u, v);
	}

	int tl = tin[head[v]], tr = tin[v];
	return seg.query (tl, tr) + query (u, par[head[v]]);
}

int lca (int u, int v) {
    if (head[u] == head[v]) {
		return (depth[u] < depth[v] ? u : v);
    }
    if (depth[head[u]] > depth[head[v]]) {
        swap (u, v);
    }

    return lca (u, par[head[v]]);
}

int main() {
	int n;
	cin >> n;

	tree = vector<vector<int>> (n);
	sz = vector<int> (n);
	tin = vector<int> (n);
	par = vector<int> (n);
	depth = vector<int> (n);

	for (int i = 0; i < n-1; i++) {
		int p, q;
		cin >> p >> q;
		p--, q--;
		tree[p].push_back (q);
		tree[q].push_back (p);
	}

	int root = 0;
	dfs1 (root, -1);
	head[root] = root;
	depth[root] = 0;
	dfs (root);
}
