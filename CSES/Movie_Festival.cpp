#include <bits/stdc++.h>

using namespace std;

struct type {
	int l, r;
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<type> data = vector<type> (n);
	for (int i = 0; i < n; i++) cin >> data[i].l >> data[i].r;

	sort (data.begin(), data.end(), [] (type &a, type &b) {
			return (a.r != b.r) ? (a.r < b.r) : (a.l > b.l);
			});

	int cur = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (data[i].l >= cur) cnt++, cur = data[i].r;
	}

	cout << cnt << '\n';

	return 0;
}
