#include <bits/stdc++.h>

using namespace std;

struct type {
	int pos, val;
	bool operator < (int b) {
		return val < b;
	};
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, tar;
	cin >> n >> tar;

	vector<type> num = vector<type> (n);
	int s[2] = {0};

	for (int i = 0; i < n; i++) cin >> num[i].val, num[i].pos = i+1;

	sort (num.begin(), num.end(), [] (type &a, type &b) {
			return a.val < b. val;
			});

	for (int i = 0; i < n; i++) {
		auto it = lower_bound (num.begin()+i+1, num.end(), tar-num[i].val);
		if (it -> val == tar-num[i].val) {
			s[0] = min (num[i].pos, it -> pos);
			s[1] = max (num[i].pos, it -> pos);
			break;
		}
	}

	if (s[0] == 0) cout << "IMPOSSIBLE\n";
	else cout << s[0] << ' ' << s[1] << '\n';

	return 0;
}
