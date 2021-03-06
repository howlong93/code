#include <bits/stdc++.h>

using namespace std;

vector<int> par, man, tic;

int fnd_root (int x) {
	if (x < 0) return -1;
	if (par[x] == x) return x;
	return par[x] = fnd_root (par[x]);
}

void merge (int a, int b) {
	int pa = fnd_root (a), pb = fnd_root (b);
	if (pa != pb && pa >= 0) par[pa] = pb;
	if (pa < 0 && pb >= 0) par[pb] = pa;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	par = vector<int> (n);
	tic = vector<int> (n);
	man = vector<int> (m);

	for (int i = 0; i < n; i++) cin >> tic[i], par[i] = i;
	for (int i = 0; i < m; i++) cin >> man[i];

	sort (tic.begin(), tic.end());

	for (int i = 0; i < m; i++) {
		auto it = upper_bound (tic.begin(), tic.end(), man[i]);
		int keep = it-tic.begin()-1, pos;
		pos = fnd_root (keep);

		if (keep < 0 || pos < 0) {
			cout << -1 << '\n';
		}
		else {
			cout << tic[pos] << '\n';
		}

		merge (pos, pos-1);
	}

	return 0;
}
