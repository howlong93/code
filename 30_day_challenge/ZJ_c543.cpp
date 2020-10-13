#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long int table[100001][10] = {0};

void build_table() {
	for (int i = 1; i <= 100000; i++) {
		table[i][9] = 1;
		for (int j = 8; j > 0; j--) {
			table[i][j] = (table[i-1][j] + table[i][j+1]) % MOD;
		}
	}
}

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	build_table();
	while (cin >> str) {
		long long int ans = 0, big = 1;
		bool flag = true;
		for (size_t i = 1; i < str.size(); i++) {
			for (int j = 1; j <= 9; j++) {
				ans = (ans + table[i][j]) % MOD;
			}
			if (str[i] < str[i-1]) flag = false;
		}

		for ( ; big < str[0]-'0'; big++)
			ans = (ans + table[str.size()][big]) % MOD;

		for (size_t i = 1; i < str.size() && str[i] >= str[i-1]; i++) {
			for (; big < str[i]-'0'; big++) {
				ans = (ans + table[str.size()-i][big]) % MOD;
			}
		}

		if (flag) ans = (ans + 1) % MOD;
		cout << ans << '\n';
	}

	return 0;
}
