#include <bits/stdc++.h>

using namespace std;

vector<int> par;

int find_root (int x) {
	if (x == par[x]) return x;
	return par[x] = find_root (par[x]);
}

int main() {
	int men, cnt = 0;
	cin >> men;
	
	par = vector<int> (men);
	vector<int> fnd (men);
	map<int, int> keep;

	for (int i = 0; i < men; i++) {
		cin >> fnd[i];
		par[i] = i;
	}

	for (int i = 0; i < men; i++) {
		int a = find_root (fnd[i]), b = find_root (i);
		if (a != b) par[a] = par[b];
	}

	for (int i = 0; i < men; i++) {
		int a = find_root (i);
		if (keep[a] == 0) cnt++;
		keep[a]++;
	}

	cout << cnt << '\n';
}
