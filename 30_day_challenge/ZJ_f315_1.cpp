#include <bits/stdc++.h>

using namespace std;

int lnth;
int bit[100001];

void add (int pos, int val) {
	while (pos <= lnth) {
		bit[pos] += val;
		pos += pos & (-pos);
	}
}

int psum (int pos) {
	int ans = 0;
	while (pos > 0) {
		ans += bit[pos];
		pos -= pos & (-pos);
	}

	return ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long int ans = 0;
	int pos;
	cin >> lnth;
	vector<int> save (lnth+1, -1);

	for (int i = 0; i < 2*lnth; i++) {
		int keep;
		cin >> pos;
		keep = psum (pos-1);
		if (save[pos] >= 0) ans += keep-save[pos];
		else save[pos] = keep;
		add (pos, 1);
	}
	
	cout << ans << '\n';

	return 0;
}
