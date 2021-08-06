#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n), b(m);
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 0; j < m; j++) cin >> b[j];
	
	sort (a.begin(), a.end());
	sort (b.begin(), b.end());
	
	int up = 0, dn = 0, ans = INT_MAX;

	while (up < n && dn < m) {
		ans = min (abs(a[up]-b[dn]), ans);
		
		if (a[up] < b[dn]) up++;
		else dn++;
	}
	
	ans = min (abs(a[n-1]-b[m-1]), ans);
	
	cout << ans << '\n';
	
	return 0;
}
