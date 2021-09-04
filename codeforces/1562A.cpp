#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;

		if (l <= r/2) cout << r/2-1+r%2 << '\n';
		else cout << r%l << '\n';
	}

	return 0;
}
