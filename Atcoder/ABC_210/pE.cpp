#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second

vector<int> par;

int fnd_root (int x) {
	if (par[x] == x) return x;
	return par[x] = fnd_root (par[x]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;

	par = vector<int> (n, 0);
	vector<pii> graph (m);
	for (int i = 0; i < m; i++) cin >> graph[i].x >> graph[i].y;
	for (int i = 0; i < n; i++) par[i] = i;
	
	sort (graph.begin(), graph.end(), [] (pii &a, pii &b) {
		return a.y < b.y;
	});
	
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int dist = graph[i].x, cost = graph[i].y;
		for (int j = 0; j < n; j++) {
			int para = fnd_root (j);
			int parb = fnd_root ( (j+dist) % n);
			
			if (para != parb) {
				ans += cost;
				par[para] = parb;
			}
		}
	}
	int test = fnd_root (0);
	for (int i = 1; i < n; i++)
		if (fnd_root (i) != test) {
			cout << -1 << '\n';
			return 0;
		}
	
	cout << ans << '\n';
	
	return 0;
}
