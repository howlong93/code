#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, n;
	cin >> n >> x;
	vector<int> nums = vector<int> (n, 0);
	for (int i = 0; i < n; i++) cin >> nums[i];
	
	int sum = 0;
	for (int i = 0; i < n; i++) sum += (i%2) ? nums[i]-1 : nums[i];
	
	cout << ((sum <= x) ? "Yes\n" : "No\n");
	
	return 0;
}
