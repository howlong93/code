#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, T;
	cin >> n >> T;
	vector<int> tm (T+5, 0);
	int start, end;
	cin >> start >> end;
	tm[start]++, tm[end+1]--;
	cout << tm.size() << '\n';
	for (int i = 0; i < n-1; i++) {
		int l, r;
		cin >> l >> r;
		
		tm[l]++, tm[r+1]--;
	}

	int ans = 0, pf = 0;
	for (int i = 1; i < start; i++) pf += tm[i];
	for (int i = start; i <= end; i++) {
		pf += tm[i];
		if (pf > n/2) ans++;
	}
	
	cout << ans << '\n';
	
	return 0;
}
