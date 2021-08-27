#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	const int mod = 1e9+7;
	int n, m;
	cin >> n >> m;
	
	vector<long long> nums = vector<long long> (m+1, 0);
	vector<int> input = vector<int> (n, 0);
	
	for (int i = 0; i < n; i++) cin >> input[i];
	
	if (input[0]) nums[input[0]] = 1;
	else {
		for (int i = 1; i <= m; i++) nums[i] = 1;
	}
	
	for (int i = 1; i < n; i++) {
		vector<long long> tmp(m+1, 0);

		int cur = input[i];
		if (cur == 0) {
			for (int i = 1; i <= m; i++) {
				if (i > 1) tmp[i] = (tmp[i]+nums[i-1]) % mod;
				if (i < m) tmp[i] = (tmp[i]+nums[i+1]) % mod;
				tmp[i] = (tmp[i]+nums[i]) % mod;
			}
		}
		else if (cur != 0) {
			tmp[cur] = (tmp[cur]+nums[cur]) % mod;
			if (cur < m) tmp[cur] = (tmp[cur]+nums[cur+1]) % mod;
			if (cur > 1) tmp[cur] = (tmp[cur]+nums[cur-1]) % mod;
		}
		nums = tmp;
	}
	
	if (input[n-1] != 0) cout << nums[input[n-1]] << '\n';
	else {
		long long sum = 0;
		for (int i = 0; i <= m; i++) sum = (sum+nums[i]) % mod;
		cout << sum << '\n';
	}
	
	return 0;
}
