#include <bits/stdc++.h>

using namespace std;

void output (vector<char> a, vector<char> b) {
	for (auto k: a) cout << k;
	for (auto k: b) cout << k;
	cout << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<char> str1, str2;
	str1 = vector<char> (n);
	str2 = vector<char> (n);

	for (int i = 0; i < n; i++) cin >> str1[i];
	for (int i = 0; i < n; i++) cin >> str2[i];

	bool tag = false;
	int cont_amt;
	cin >> cont_amt;
	for (int i = 0; i < cont_amt; i++) {
		int opt, a, b;
		cin >> opt >> a >> b;
		a--, b--;
		if (opt == 1) {
			if (a < n && b < n) {
				if (!tag) swap (str1[a], str1[b]);
				else swap (str2[a], str2[b]);
				continue;
			}
			if (a >= n && b >= n) {
				a -= n, b -= n;
				if (!tag) swap (str2[a], str2[b]);
				else swap (str1[a], str1[b]);
				continue;
			}
			
			if (a > b) swap (a, b);
			b -= n;
			if (!tag) swap (str1[a], str2[b]);
			else swap (str1[b], str2[a]);
		}
		else if (opt == 2) {
			tag ^= 1;
		}
	}

	if (!tag) output(str1, str2);
	else output (str2, str1);

	return 0;
}
