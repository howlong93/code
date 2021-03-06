#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	long long ans = 0;
	cin >> n;

	vector<int> num = vector<int> (n);
	for (int i = 0; i < n; i++)	cin >> num[i];

	sort (num.begin(), num.end());

	for (int i = 0; i < n/2; i++) {
		ans += num[n-1-i] - num[i];
	}

	cout << ans << '\n';

	return 0;
}
