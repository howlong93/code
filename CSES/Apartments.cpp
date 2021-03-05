#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m, lim;
	cin >> n >> m >> lim;

	vector<int> man, house;

	man = vector<int> (n);
	house = vector<int> (m);

	for (int i = 0; i < n; i++) cin >> man[i];
	for (int i = 0; i < m; i++) cin >> house[i];

	sort (man.begin(), man.end());
	sort (house.begin(), house.end());

	int u = 0, d = 0, ans = 0;
	while (u < n && d < m) {
		int keep = man[u]-house[d];
		if ((keep >= 0 && keep <= lim) || (keep < 0 && keep >= -lim))
			ans++, u++, d++;
		else if (keep < 0) u++;
		else d++;
	}

	cout << ans << '\n';

	return 0;
}
