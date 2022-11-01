#include <bits/stdc++.h>

using namespace std;

#define MOD 998244353

int main() {
	long long num[6], ans = 1, temp = 1;

	for (int i = 0; i < 6; i++) {
		cin >> num[i];
		num[i] %= MOD;
	}

	for (int i = 0; i < 3; i++) {
		ans = ans * num[i] % MOD;
		temp = temp * num[i+3] % MOD;
	}

	ans -= temp;

	if (ans < 0) ans += MOD;

	cout << ans << '\n';

	return 0;
}
