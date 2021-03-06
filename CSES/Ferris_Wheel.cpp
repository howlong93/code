#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, lim, ans = 0;
	cin >> n >> lim;

	vector<int> num = vector<int> (n);

	for (int i = 0; i < n; i++) cin >> num[i];

	sort (num.begin(), num.end());
	int l = 0, r = num.size()-1;

	while (r > l) {
		if (num[l] + num[r] <= lim) r--, l++;
		else r--;

		ans++;
	}
	if (r == l) ans++;

	cout << ans << '\n';

	return 0;
}
