#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> input = vector<int> (n, 0);
	for (int i = 0; i < n; i++) cin >> input[i];
	
	int ans = 0;
	map<int, int> col;
	
	for (int i = 0; i < k; i++) col[input[i]]++;
	ans = col.size();

	for (int i = 0; i < n-k; i++) {
		col[input[i]]--;
		if (col[input[i]] <= 0) col.erase (input[i]);
		col[input[i+k]]++;
		
		int sz = col.size();
		ans = max (ans, sz);
	}
	
	cout << ans << '\n';
	
	return 0;
}
