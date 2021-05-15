#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, fx = 0;
	cin >> n;

	m = n;
	while (m) {
		fx += m % 10;
		m /= 10;
	}

	if (n % fx) cout << "No\n";
	else cout << "Yes\n";

	return 0;
}
