#include <bits/stdc++.h>

using namespace std;

#define iv vector<int>
#define bv vector<bool>
#define upper 46340

iv prime;
bv tb (upper, 0);

void bd_prime () {
	tb[0] = tb[1] = 1;
	for (long long i = 2; i < upper; i++) {
		if (!tb[i]) {
			prime.emplace_back (i);
			for (long long j = i << 1; j < upper; j += i) {
				tb[i] = 1;
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long n, test_case = 0;
	bd_prime();

	while (cin >> n && n > 0) {
		long long ans = 0;
		cout << "Case " << ++test_case << ": ";
		if (n == 1) {
			cout << 2 << '\n';
			continue;
		}
		long long m = n;
		for (size_t i = 0; i < prime.size() && prime[i] <= n; i++) {
			long long cnt = 1;
			while (! (n%prime[i])) {
				cnt *= prime[i];
				n /= prime[i];
			}

			if (cnt > 1) ans += cnt;
		}

		if (n != 1) ans += n;
		if (ans == m) ans++;

		cout << ans << '\n';
	}

	return 0;
}
