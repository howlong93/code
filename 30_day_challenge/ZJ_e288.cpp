#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie (0);
	ios_base::sync_with_stdio(false);

	int m, n, cnt = 0;
	map <long long int, int> mem;
	long long int x = 0;
	cin >> m >> n;
	string str;
	
	for (int i = 0; i < m; i++) x += (1LL << i);

	for (int i = 0; i < n; i++) {
		cin >> str;
		long long int keep = 0;
		for (auto k: str) {
			if (k <= 'Z' && k >= 'A') keep |= (1LL << (k-'A'));
			else keep |= (1LL << (k-'a'+26));
		}

		if (mem.find (keep ^ x) != mem.end()) cnt += mem[keep ^ x];
		mem[keep]++;
	}

	cout << cnt << '\n';

	return 0;
}
