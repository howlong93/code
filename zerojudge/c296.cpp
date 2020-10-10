#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;

    for (int i = n-k+1; i <= n; i++) {
	ans = (ans + m) % i;
    }

    cout << ans+1;

    return 0;
}
