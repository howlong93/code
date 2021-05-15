#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	int sm = INT_MAX, bi = 0, a;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		bi = max (a, bi);
	}

	for (int i = 0; i < n; i++) {
		cin >> a;
		sm = min (a, sm);
	}

	if (sm-bi >= 0) cout << sm-bi+1 << '\n';
	else cout << 0 << '\n';

	return 0;
}
