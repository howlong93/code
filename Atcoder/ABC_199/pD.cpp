#include <bits/stdc++.h>

using namespace std;

vector<int> rts, head;
vector<bool> vis;



int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph = vector<vector<int>> (n+1);

	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		graph[p].push_back (q);
		graph[q].push_back (p);
	}

	head = vector<int> (n+1);
	vis = vector<bool> (n+1, 0);
	for (int i = 1; i <= n; i++) head[i] = i;

	for (int i = 1; i <= n; i++)  
