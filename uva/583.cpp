#include <bits/stdc++.h>

using namespace std;

#define iv vector<int>
#define bv vector<bool>

iv ans, prime;
bv vis = bv (65537, 1);

void build_table (int x) {
	if (x > 65536) return;
	if (vis[x]) {
		prime.emplace_back (x);
		for (int j = 2; j*x <= 65536; j++) {
			vis[j*x] = 0;
		}
	}
	build_table(x+1);
}

void calc_ans (int x) {
	int keep = x;
	for (size_t i = 0; i < prime.size(); i++) {
		if (prime[i] > x) break;
		while (keep % prime[i] == 0) {
			ans.emplace_back (prime[i]);
			keep/=prime[i];
		}
	}
	if (keep != 1) ans.emplace_back (keep);
}

int main () {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;

	build_table (2);

	while (cin >> n && n != 0) {
		ans.clear();
		if (n > 0) {
			calc_ans (n);
		}
		else {
			ans.emplace_back (-1);
			calc_ans (n*-1);
		}

		cout << n << " =";
		cout << ' ' << ans[0];
		for (size_t i = 1; i < ans.size(); i++)
			cout << " x " << ans[i];
		cout << '\n';
	}

	return 0;
}
