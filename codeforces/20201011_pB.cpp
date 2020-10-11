#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

    int n, amt, t;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> amt >> t;
        vector<int> lit(amt);
        pair<int, int> keep;

        for (int j = 0; j < amt; j++) cin >> lit[j];

        sort (lit.begin(), lit.end());

		long long int ans = 0;
		for (int j = 1; j <= amt && j <= t+1; j++) ans += lit[amt-j];

        cout << ans << '\n';
    }

    return 0;
}
