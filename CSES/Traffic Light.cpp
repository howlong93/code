#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> input (m), output(m);
	set<int> pos;
	pos.insert (0), pos.insert (n);

	for (int i = 0; i < m; i++) cin >> input[i];
	for (int i = 0; i < m; i++) pos.insert (input[i]);
	
	int ans = 0;
	for (auto it = pos.begin(); it != pos.end(); ) {
		if (*it == n) break;
		int cur = *it;
		it++;
		ans = max (ans, *it-cur);
	}

	output[m-1] = ans;
	for (int i = m-1; i > 0; i--) {
		auto it = pos.find (input[i]);
		auto next = it, prev = it;
		
		next++, prev--;
		
		ans = max (ans, *next-*prev);
		pos.erase(it);
		
		output[i-1] = ans;
	}
	
	for (auto k: output) cout << k << ' ';
	cout << '\n';
	
	return 0;
}
