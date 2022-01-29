#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int test;
	cin >> test;

	while (test--) {
		int n, k;
		cin >> n >> k;

		if (k == n-1) {
			if (n == 4) cout << -1 << '\n';
			else {
				cout << n-1 << ' ' << n-2 << '\n';
				cout << n-3 << ' ' << 1 << '\n';
				cout << 0 << ' ' << 2 << '\n';
				for (int i = 3; i < n/2; i++) {
					cout << i << ' ' << n-i-1 << '\n';
				}
			}
		}
		else if (k == 0) {
			for (int i = 0; i < n/2; i++) {
				cout << i << ' ' << n-i-1 << '\n';
			}
		}
		else {
			cout << 0 << ' ' << n-k-1 << '\n';
			cout << k << ' ' << n-1 << '\n';
			for (int i = 1; i < n/2; i++) {
				if (i == k || i == n-k-1) continue;
				cout << i << ' ' << n-i-1 << '\n';
			}
		}
	}

	return 0;
}
