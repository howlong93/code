#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

long long sqr (int x) {
	return 1LL * x * x;
}

long long dist (pii x, pii y) {
	return sqr (x.first - y.first) + sqr (x.second - y.second);
}

long long closest_pair (vector<pii> pnt) {
	set<pii> swp;

	long long ans = 8e18;
	for (size_t l = 0, r = 0; r < pnt.size(); r++) {
		pii now = pnt[r];
		while (l < r && sqr (now.second - pnt[l].second) >= ans) {
			swp.erase (pnt[l]);
			l++;
		}
		
		auto it = swp.lower_bound (now);
		for (int i = 0; i < 4; i++, it++) {
			if (it == swp.end()) break;
			ans = min (ans, dist (now, *it));
		}

		it = swp.lower_bound (now);
		for (int i = 0; i < 4; i++) {
			if (it == swp.begin()) break;
			it--;
			ans = min (ans, dist (now, *it));
		}

		swp.insert (pnt[r]);
	}

	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, int>> pnt = vector<pair<int, int>> (n);

	for (int i = 0; i < n; i++) cin >> pnt[i].first >> pnt[i].second;

	sort (pnt.begin(), pnt.end(), [] (pii &a, pii &b) {
			return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);
			});

	cout << closest_pair(pnt) << '\n';

	return 0;
}
