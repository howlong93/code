#include <bits/stdc++.h>

using namespace std;

vector<int> nums, pos;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m, cnt = 1;
	cin >> n >> m;

	nums = vector<int> (n+1), pos = vector<int> (n+1);

	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		pos[nums[i]] = i;
	}

	for (int i = 2; i <= n; i++)
		if (pos[i] < pos[i-1]) cnt++;


	for (int i = 0; i < m; i++) {
		int a, b, cur = 0;
		cin >> a >> b;
		if (a > b) swap (a, b);

		swap (nums[a], nums[b]);
		a = nums[a], b = nums[b];

		if (a > 1 && pos[a] < pos[a-1]) cur--;
		if (a < n && pos[a+1] < pos[a]) cur--;
		if (a != b-1 && pos[b] < pos[b-1]) cur--;
		if (b < n && pos[b+1] < pos[b]) cur--;

		swap (pos[a], pos[b]);

		if (b != a-1 && pos[a] < pos[a-1]) cur++;
		if (a < n && pos[a+1] < pos[a]) cur++;
		if (b > 1 && pos[b] < pos[b-1]) cur++;
		if (b < n && pos[b+1] < pos[b]) cur++;

		cnt += cur;
		cout << cnt << '\n';
	}

	return 0;
}
