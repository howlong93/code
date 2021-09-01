#include <bits/stdc++.h>

using namespace std;

vector<int> par;

int fnd_root (int x) {
	if (par[x] == x) return x;
	return par[x] = fnd_root (par[x]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	par = vector<int> (n+1);
	for (int i = 0; i <= n; i++) par[i] = i;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		int pa, pb;
		pa = fnd_root (a);
		pb = fnd_root (b);
		
		if (pa != pb) par[pa] = pb;
	}
	
	map<int, int> cnt;
	vector<int> ans;
	for (int i = 1; i <= n; i++) cnt[fnd_root(i)]++;
	
	for (auto k: cnt) ans.push_back (k.first);
	cout << ans.size()-1 << '\n';
	
	for (int i = 1; i < ans.size(); i++)
		cout << ans[i-1] << ' ' << ans[i] << '\n';

	return 0;
}
