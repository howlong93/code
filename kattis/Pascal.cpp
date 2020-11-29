#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			cnt = n/i;
			break;
		}
	}

	if (cnt == 0) cout << n-1 << '\n';
	else cout << n-cnt << '\n';

	return 0;
}
