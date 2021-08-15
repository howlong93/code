#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> nums = vector<int> (n, 0);
	set<int> data;
	for (int i = 0; i < n; i++) cin >> nums[i], data.insert (i);
	
	int cnt = 1;
	while (data.size() > 1) {
		for (auto k: data) {
			for (int i = 0; i < n; i++) {
				if (i != k && cnt % nums[i] == 0) data.erase (i);
			}
			cnt++;
		}
	}
	
	cout << *data.begin()+1 << '\n';
	
	return 0;
}
