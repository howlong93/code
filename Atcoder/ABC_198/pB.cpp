#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 0) {
		cout << "Yes\n";
		return 0;
	}

	while (!(n % 10)) n /= 10;

	vector<int> f, b;
	while (n) {
		f.emplace_back (n % 10);
		n /= 10;
	}

	b = f;
	reverse (b.begin(), b.end());

	if (b == f) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
