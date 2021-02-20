#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, cnt = 1;
	cin >> n;

	vector<int> nums = vector<int> (n+1), pos = vector<int> (n+1);

	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		pos[nums[i]] = i;
	}

	for (int i = 2; i <= n; i++)
		if (pos[i] < pos[i-1]) cnt++;

	cout << cnt << '\n';

	return 0;
}
