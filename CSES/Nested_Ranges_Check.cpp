#include <bits/stdc++.h>

using namespace std;

struct Type {
	int a, b;
	int pos;
	int u, d;
};

#define vip vector<Type>

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vip nums = vip (n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i].a >> nums[i].b;
		nums[i].pos = i;
	}

	sort (nums.begin(), nums.end(), [] (Type &a, Type &b) {
			if (a.a != b.a) return a.a < b.a;
			return a.b > b.b;
		});

	vector<int> suffix = vector<int> (n), prefix = vector<int> (n);
	suffix[n-1] = nums[n-1].b, prefix[0] = nums[0].b;
	for (int i = 1; i < n; i++) prefix[i] = max (nums[i].b, prefix[i-1]);
	for (int i = n-2; i >= 0; i--) suffix[i] = min (nums[i].b, suffix[i+1]);

	for (int i = 0; i < n-1; i++)
		if (nums[i].b >= suffix[i+1]) nums[i].u = 1;
		else nums[i].d = 0;

	for (int i = n-1; i > 0; i--) 
		if (nums[i].b <= prefix[i-1]) nums[i].d = 1;
		else nums[i].d = 0;

	sort (nums.begin(), nums.end(), [] (Type &a, Type &b) {
			return a.pos < b.pos;
		});

	for (auto k: nums) cout << k.u << ' ';
	cout << '\n';
	for (auto k: nums) cout << k.d << ' ';
	cout << '\n';

	return 0;
}
