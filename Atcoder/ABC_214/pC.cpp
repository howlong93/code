#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> get(n), give(n);
	for (int i = 0; i < n; i++) cin >> give[i];
	for (int j = 0; j < n; j++) cin >> get[j];
	
	for (int i = 1; i < n; i++) get[i] = min (get[i], get[i-1]+give[i-1]);
	
	int cur = get[n-1] + give[n-1];
	for (int i = 0; i < n; i++) {
		get[i] = min (cur, get[i]);
		cur = get[i] + give[i];
	}
	
	for (int i = 0; i < n; i++) cout << get[i] << '\n';
	
	return 0;
}

