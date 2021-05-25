#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;

	vector<int> u, d;
	u = d = vector<int> (n);
	
	for (int i = 0; i < n; i++) cin >> u[i];
	for (int i = 0; i < n; i++) cin >> d[i];

	for (int i = 0; i < n; i++) 
		if (u[i]-d[i] > 0) ans += u[i]-d[i];

	cout << ans << '\n';

	return 0;
}
