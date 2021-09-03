#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, mod = 1000000009, ans = 1;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        long long t = (v[i] - v[i - 1]) % mod;
        ans *= t;
        ans %= mod;
    }
    if (ans < 0) ans += mod;
    cout << ans;

	return 0;
}
