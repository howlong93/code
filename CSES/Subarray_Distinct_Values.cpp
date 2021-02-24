#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, lim;
	cin >> n >> lim;

	vector<int> nums = vector<int> (n);
	map<int, int> fnd;

	for (int i = 0; i < n; i++) cin >> nums[i];

	int f = 0, s = 0;
	long long ans = 0;

	fnd[nums[0]] = 1;
	while (f < n && s < n) {
		while (fnd.size() <= lim && s < n) {
			fnd[nums[++s]]++;
		}

		ans += s-f;
		
		fnd[nums[f]]--;
		if (fnd[nums[f]] == 0) fnd.erase (nums[f]);

		f++;
	}

	for (int i = f; i <= s; i++) ans += s-i;

	cout << ans << '\n';

	return 0;
}
