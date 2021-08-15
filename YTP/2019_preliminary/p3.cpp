#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main() {
	int n;
	cin >> n;
	
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		int pos;
		cin >> pos;
		cnt[pos]++;
	}
	int v;
	cin >> v;
	
	int ans = 0;
	for (auto k: cnt) {
		if (k.first > v/2) break;
		else if (v % 2 == 0 && k.first == v/2)
			ans += k.second * (k.second-1) / 2;
		else ans += k.second * cnt[v-k.first];
	}
	
	cout << ans << '\n';
	
	return 0;
}
