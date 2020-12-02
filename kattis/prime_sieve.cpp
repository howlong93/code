#include <bits/stdc++.h>

using namespace std;

#define bv vector<bool>
#define iv vector<int>

int cnt = 0, n, q, query;
bv prime;

void build_table() {
	int i;
	for (i = 4; i <= n; i += 2) prime[i] = 0;
	cnt++;
	for (i = 3; i*i <= n; i += 2) {
		if (prime[i]) {
			cnt++;
			for (int j = i*i; j <= n; j += 2*i) prime[j] = 0;
		}
	}

	for (; i <= n; i++)
		if (prime[i]) cnt++;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> q;
	prime = bv (n+1, 1);

	prime[1] = 0;
	build_table();

	cout << cnt << '\n';
	for (int i = 0; i < q; i++) {
		cin >> query;
		cout << prime[query] << '\n';
	}

	return 0;
}
