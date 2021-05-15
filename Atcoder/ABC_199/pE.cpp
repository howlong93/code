#include <bits/stdc++.h>

using namespace std;

const int N = 20;
vector<long long> dp;
vector<pair<int, int>> C[N];

bool ok (int S) {
	int x = __builtin_popcount (S);
	for (auto k: C[x]) {
		int y = k.first;
		int z = k.second;
		for (int i = 0; i < y; i++) {
			if (S & (1 << i)) {
				z--;
			}
		}
		if (z < 0) return false;
	}

	return true;
}

int main() {
	int n, m;
	cin >> n >> m;

	dp.resize(1 << N);

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		C[x].push_back ({y, z});
	}

	dp[0] = 1;
	for (int i = 1; i < (1 << n); i++) {
		dp[i] = 0;
		if (ok(i)) {
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					dp[i] += dp[i ^ (1 << j)];
				}
			}
		}
	}

	cout << dp[(1 << n) - 1] << '\n';

	return 0;
}
