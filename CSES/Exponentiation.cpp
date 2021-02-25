#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

long long fast_query(long long n, long long m, long long mod) {
    long long ret = 1;
    while (m) {
        if (m % 2) ret = ret * n % mod;

        m >>= 1;
        n = n * n % mod;
    }

    return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    int tst_amt;
    cin >> tst_amt;

    while (tst_amt--) {
        long long a, b;
        cin >> a >> b;

        cout << fast_query(a, b, MOD) << '\n';
    }

	return 0;
}
