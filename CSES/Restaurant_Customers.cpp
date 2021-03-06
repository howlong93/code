#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, a, b, ans = 0, cnt = 0;
	cin >> n;

	vector<int> cus = vector<int> (2 * n);
	for (int i = 0; i < 2*n; i += 2) {
		cin >> a >> b;
		
		cus[i] = a, cus[i+1] = -b;
	}

	sort (cus.begin(), cus.end(), [] (int &x, int &y) {
			return abs(x) < abs(y);
		});

	for (int i = 0; i < 2*n; i++) {
		if (cus[i] > 0) cnt++;
		else cnt--;

		ans = max (ans, cnt);
	}

	cout << ans << '\n';

	return 0;
}
