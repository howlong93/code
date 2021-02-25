#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
long long table[1000005];

void build_table() {
	table[0] = table[1] = 1;
	for (long long i = 2; i <= 1000000; i++)
		table[i] = table[i-1] * i % MOD;
}

long long fast_query (long long n, long long m) {
	long long ret = 1;
	while (m) {
		if (m%2) ret = ret * n % MOD;

		m >>= 1;
		n = n*n % MOD;
	}

	return ret;
}

long long C_nm (int n, int m) {
	long long up, down;
	down = table[m] * table[n-m] % MOD;
	up = table[n];

	return fast_query(down, MOD-2) * up % MOD;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int tst_amt;
	cin >> tst_amt;

	build_table ();
	while (tst_amt--) {
		int a, b;
		cin >> a >> b;

		cout << C_nm (a, b) << '\n';
	}

	return 0;
}
