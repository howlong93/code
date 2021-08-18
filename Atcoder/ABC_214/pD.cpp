#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u, v, lnth;
	bool operator < (const Edge &b) {
		return (lnth != b.lnth) ? lnth < b.lnth : u < b.u;
	}
};

vector<int> par, sz;

int fnd_rt (int x) {
	if (x == par[x]) return x;
	return par[x] = fnd_rt (par[x]);
}

void merge (int x, int y) {
	par[x] = y;
	sz[y] += sz[x];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<Edge> edge(n-1);
	par = sz = vector<int> (n+1, 1);

	for (int i = 0; i < n-1; i++) cin >> edge[i].u >> edge[i].v >> edge[i].lnth;
	sort (edge.begin(), edge.end());

	long long ans = 0;
	for (int i = 0; i <= n; i++) par[i] = i;

	for (int i = 0; i < n-1; i++) {
		int pa = fnd_rt (edge[i].u);
		int pb = fnd_rt (edge[i].v);

		ans += 1LL * edge[i].lnth * sz[pa] * sz[pb];
		merge (pa, pb);
	}

	cout << ans << '\n';

	return 0;
}
