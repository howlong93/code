#include <bits/stdc++.h>

using namespace std;

#define INF 1e9+7
#define pii pair<int, int>

struct Edge {
	int a, b, lnth, tm;
};

vector<vector<int>> d;

int main() {
	int n, m, tl;
	cin >> n >> m >> tl;
	
	d = vector<vector<int>> (n+1, vector<int> (tl+1, INF));
	vector<Edge> edge (m);
	
	for (int i = 0; i < m; i++) cin >> edge[i].a >> edge[i].b >> edge[i].tm >> edge[i].lnth;
	
	for (int i = 0; i <= tl; i++) d[1][0] = 0;
	
	for (int i = 0; i < n; i++) {
		for (auto k: edge) {
			for (int j = tl; j >= 0 && j - k.lnth >= 0; j--) {
				d[k.a][j] = min (d[k.a][j], d[k.b][j-k.lnth] + k.tm);
				d[k.b][j] = min (d[k.b][j], d[k.a][j-k.lnth] + k.tm);
			}
		}
	}
	
	int ans = INT_MAX;
	for (int i = 0; i <= tl; i++) ans = min (ans, d[n][i]);
	
	cout << (ans != INF ? ans : -1) << '\n';
	
	return 0;
}
