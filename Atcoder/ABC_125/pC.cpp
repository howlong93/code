#include <bits/stdc++.h>

using namespace std;

int gcd (int x, int y) {
	int z;
	while (x%y) {
		z = y;
		y = x%y;
		x = z;
	}

	return y;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	vector<int> num, pf, sf;

	cin >> n;
	num = pf = sf = vector<int> (n);

	for (int i = 0; i < n; i++) cin >> num[i];

	pf[0] = num[0];
	for (int i = 1; i < n; i++) pf[i] = gcd (pf[i-1], num[i]);

	sf[n-1] = num[n-1];
	for (int i = n-2; i >= 0; i--) sf[i] = gcd (sf[i+1], num[i]);

	int ans = max ({pf[n-1], pf[n-2], sf[1]});
	for (int i = 1; i < n-1; i++)
		ans = max (ans, gcd (pf[i-1], sf[i+1]));

	cout << ans << '\n';

	return 0;
}
