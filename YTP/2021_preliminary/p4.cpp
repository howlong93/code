#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	const int INF = 1e9+7;
	int n, m;
	cin >> n >> m;

	vector<vector<int>> fire(101);
	for (int i = 0; i < n; i++) {
		int tmp, tm;
		cin >> tmp >> tm;
		fire[tm].emplace_back (tmp);
	}

	vector<int> boat = vector<int> (m+2, INF);
	for (int t = 1; t <= 10000; t++) {
		if (t <= 100) {
			for (auto k: fire[t]) {
				boat[k] = min (boat[k], t);
			}
		}
		for (int i = 1; i <= m; i++) {
			if (boat[i] == t) {
				boat[i+1] = min(boat[i+1], t+1);
				boat[i-1] = min(boat[i-1], t+1);
			}
		}
	}

	for (int i = 1; i <= m; i++) cout << boat[i] << ' ';
	cout << '\n';

	return 0;
}
