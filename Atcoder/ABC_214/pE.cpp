#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<pii> data(n);
		for (int i = 0; i < n; i++) cin >> data[i].x >> data[i].y;

		sort (data.begin(), data.end(), [] (pii &a, pii &b) {
			return a.x != b.x ? a.x < b.x : a.y < b.y;
		});

		bool flag = true;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (cur <= data[i].y) cur = max(cur, data[i].x)+1;
			else {
				flag = false;
				break;
			}
		}

		cout << (flag ? "Yes\n" : "No\n");
	}

	return 0;
}
