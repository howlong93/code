#include <bits/stdc++.h>

using namespace std;

#define iv vector<int>

int ma_num = 1;
vector<iv> graph;
iv vis;

void dfs (int x) {
	iv prob = iv (ma_num+1, 1);
	for (auto k: graph[x]) {
		if (vis[k]) prob[vis[k]] = 0;
	}
	
	for (int i = 1; i <= ma_num; i++) {
		if (prob[i]) {
			vis[x] = i;
			break;
		}
	}
	if (vis[x] == 0) {
		ma_num++;
		vis[x] = ma_num;
	}
	
	for (auto k: graph[x]) {
		if (!vis[k]) dfs (k);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	graph = vector<iv> 	(n+1);
	vis = iv (n+1, 0);
	
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		graph[l].emplace_back (r);
		graph[r].emplace_back (l);
	}
	
	dfs (1);
	
	cout << ma_num << '\n';
	for (int i = 1; i < n; i++) {
		cout << vis[i] << ' ';
	}
	cout << vis[n] << '\n';
}
