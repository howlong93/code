#include <bits/stdc++.h>

using namespace std;

vector<int> LIS;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> nums = vector<int> (n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	LIS.emplace_back (nums[0]);
	for (size_t i = 1; i < nums.size(); i++) {
		if (nums[i] >= LIS[LIS.size()-1]) LIS.emplace_back (nums[i]);
		else *upper_bound (LIS.begin(), LIS.end(), nums[i]) = nums[i];

	}
	 
	cout << LIS.size() << '\n';

	return 0;
}
