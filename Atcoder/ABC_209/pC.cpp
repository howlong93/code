#include <bits/stdc++.h>

using namespace std;

int main() {
	const int mod = 1e9+7;
	int n;
	cin >> n;
	vector<long long> nums = vector<long long> (n, 0);
	
	for (int i = 0; i < n; i++) cin >> nums[i];
	long long cur = 0, ans = 1;
	
	sort (nums.begin(), nums.end());
	
	for (int i = 0; i < n; i++) {
		if (nums[i]-i < 0) {
			cout << 0 << '\n';
			return 0;
		}
		ans = ans * (nums[i]-i) % mod;
	}
	
	cout << ans << '\n';
	
	return 0;
}

