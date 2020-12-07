#include <bits/stdc++.h>

using namespace std;

#define MAX 50000
#define iv vector<long long int>

iv table;

void build_table (int x) {
	table[1] = 1;
	for (int i = 2; i <= x; i++) {
		if (!table[i]) {
			for (int j = i; j <= x; j += i) {
				if (!table[j]) table[j] = j;
				table[j] = table[j] /i * (i-1);
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	table = iv (MAX+1, 0);
	build_table (MAX);

	int n;
	while (cin >> n && n > 0) {
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}

		long long int ans = 1;
		for (int i = 2; i <= n; i++) {
			ans += 2 * table[i];
		}

		cout << ans << '\n';
	}

	return 0;
}
