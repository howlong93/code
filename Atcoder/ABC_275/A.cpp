#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, num = 0, mx = 0, index = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;

		if (num > mx) mx = num, index = i;
	}

	cout << index << '\n';

	return 0;
}
