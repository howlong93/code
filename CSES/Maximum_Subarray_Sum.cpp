#include <bits/stdc++.h>

using namespace std;

#define ll long long
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
   	long long ans = LLONG_MIN;

	cin >> n;

	vector<ll> num = vector<ll> (n);
	vector<ll> dp = vector<ll> (n, 0);
	for (int i = 0; i < n; i++) cin >> num[i];

	dp[0] = num[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max (num[i], dp[i-1]+num[i]);
	}

	for (int i = 0; i < n; i++) ans = max (ans, dp[i]);
	cout << ans << '\n';

	return 0;
}
