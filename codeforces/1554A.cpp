#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int q_amt;
	cin >> q_amt;
	while (q_amt--) {
		int n;
		cin >> n;
		
		vector<long long> nums = vector<long long> (n, 0);
		for (int i = 0; i < n; i++) cin >> nums[i];
		
		long long ans = 0;
		for (int i = 0; i < n-1; i++) ans = max (nums[i] * nums[i+1], ans);
		
		cout << ans << '\n';
	}
	
	return 0;
}
