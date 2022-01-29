#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	while (n--) {
		int amt;
		cin >> amt;

		vector<int> a(amt), b(amt);

		for (int i = 0; i < amt; i++) cin >> a[i];
		for (int j = 0; j < amt; j++) cin >> b[j];

		for (int i = 0; i < amt; i++) {
			if (a[i] > b[i]) swap (a[i], b[i]);
		}

		int mxa = 0, mxb = 0;
		for (int i = 0; i < amt; i++) {
			mxa = max (mxa, a[i]);
			mxb = max (mxb, b[i]);
		}

		cout << mxa * mxb << '\n';
	}

	return 0;
}
