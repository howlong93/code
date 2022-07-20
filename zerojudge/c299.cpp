#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, temp;
	cin >> n;
	
	int mx = 0, mn = 2000;
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		mx = max (mx, temp);
		mn = min (mn, temp);
	}
	
	cout << mn << ' ' << mx << ' ';
	
	if ((mx - mn + 1) == n) cout << "yes\n";
	else cout << "no\n";
	
	return 0;
}
