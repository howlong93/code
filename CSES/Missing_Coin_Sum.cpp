#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	long long cur_num = 1;
	cin >> n;

	vector<int> nums = vector<int> (n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sort (nums.begin(), nums.end());

	for (int i = 0; i < n; i++) {
		if (cur_num < nums[i]) break;

		if (cur_num >= nums[i]) cur_num += nums[i];
	}
	cout << cur_num << '\n';

	return 0;
}
