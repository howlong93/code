#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;

	while (n) {
		int keep = 0, save = n;
		for (int i = 1; i <= 7; i++) {
			keep = max (keep, save % 10);
			save /= 10;
		}

		n -= keep;
		cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
