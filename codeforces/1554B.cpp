#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int q_amt;
	cin >> q_amt;
	
	while (q_amt--) {
		int n, k;
		cin >> n >> k;
		vector<int> nums = vector<int> (n+1, 0);
		for (int i = 1; i <= n; i++) cin >> nums[i];
		
		long long ans = INT_MIN;
		int st = max (1, n-2*k-1);
		for (int i = st; i <= n; i++) {
			for (int j = i+1; j <= n; j++) {
				ans = max (ans, 1LL*i*j - k*(nums[i]|nums[j]));
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
