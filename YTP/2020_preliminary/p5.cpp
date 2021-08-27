#include <bits/stdc++.h>

using namespace std;

vector<int> par;

int fnd_root (int x) {
	if (x == par[x]) return x;
	return par[x] = fnd_root (par[x]);
}

int main() {
	int n;
	cin >> n;

	par = vector<int> (n, 0);
	map<int, int> ang;

	for (int i = 0; i < n; i++) par[i] = i;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p, p--;
		if (p == i || ang[p] >= 1) {
			cout << -1 << '\n';
			return 0;
		}

		ang[p]++;
		int pa = fnd_root (p), pb = fnd_root (i);
		par[pa] = pb;
	}

	ang.clear();
	for (int i = 0; i < n; i++) cout << fnd_root(i) << ' ', ang[fnd_root(i)]++;
	cout << '\n';
	cout << ang.size() << '\n';

	return 0;
}
