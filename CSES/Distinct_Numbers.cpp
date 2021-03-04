#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, k;
	set<int> s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		s.insert (k);
	}

	cout << s.size() << '\n';

	return 0;
}
