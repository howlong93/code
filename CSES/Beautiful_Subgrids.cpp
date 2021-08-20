#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("popcnt")

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<bitset<3002>> grid(n);

	for (int i = 0; i < n; i++) cin >> grid[i];

	long long ans = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			int cnt = (grid[i] & grid[j]).count();
			ans += cnt * (cnt-1) /2;
		}
	}

	cout << ans << '\n';

	return 0;
}
