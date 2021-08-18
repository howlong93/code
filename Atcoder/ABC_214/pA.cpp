#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 125) cout << 4 << '\n';
	else if (n >= 212) cout << 8 << '\n';
	else cout << 6 << '\n';

	return 0;
}
