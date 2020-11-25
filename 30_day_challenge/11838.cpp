#include <bits/stdc++.h>

using namespace std;

#define iv vector<int>
#define bv vector<bool>

vector<iv> graph, rev, scc;
iv kexit, save;
bv vis;

int n, m, cnt;

void mk_stmp(int x) {
	vis[x] = 1;
	for (auto k: rev[x])
		if (!vis[k]) mk_stmp (k);
	save.emplace_back (x);
}

void dfs (int x) {
	cnt++;
	vis[x] = 1;
	for (auto k: graph[x]) {
		if (!vis[k]) dfs (k);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> n >> m && (n != 0 || m != 0)) {
		cnt = 0;
		int orig, dest, way;

		graph = rev = scc = vector<iv> (n+1);
		vis = vector<bool> (n+1, 0);
		kexit = iv (n+1);

		for (int i = 0; i < m; i++) {
			cin >> orig >> dest >> way;
			graph[orig].emplace_back (dest);
			rev[dest].emplace_back (orig);

			if (way == 2) {
				graph[dest].emplace_back (orig);
				rev[orig].emplace_back (dest);
			}
		}

		for (int i = 1; i <= n; i++) {
			if (!vis[i])
				mk_stmp (i);
		}
		for (int i = 1; i <= n; i++) vis[i] = 0;

		reverse (save.begin(), save.end());
		dfs (save[0]);
		cout << ((cnt == n) ? 1 : 0) << '\n';
	}

	return 0;
}
