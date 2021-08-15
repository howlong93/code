#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int x[n], y[n];
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	
	sort (x, x+n);
	sort (y, y+n);
	
	for (int i = 0; i < n; i++) cout << x[i] << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++) cout << y[i] << ' ';
	cout << '\n';
	cout << x[n/2] << ' ' << y[n/2] << '\n';
	
	int ans = 0;
	ans += x[n/2]-x[0] + y[n/2]-y[0];
	ans += x[n-1]-x[n/2] + y[n-1]-y[n/2];
	
	cout << ans << '\n';
	
	return 0;
}
