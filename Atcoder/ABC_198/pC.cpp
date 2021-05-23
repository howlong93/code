#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x, y;
	cin >> n >> x >> y;

	long long dist = sqrt(1ll*x*x + 1ll*y*y);
	double dir = sqrt (1ll*x*x + 1ll*y*y);

	if (dir == 0) cout << 0 << '\n';
	else if (dir == n) cout << 1 << '\n';
	else if (dir < n) cout << 2 << '\n';
	else {
		if (dir-n * (dist/n)) {
			cout << dist / n + 1 << '\n';
		}
		else {
			cout << dist / n << '\n';
		}
	}

	return 0;
}
