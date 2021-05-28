#include <bits/stdc++.h>

using namespace std;

vector <int> head;

int find_root (int x) {
	if (head[x] == x) return x;
	return head[x] = find_root (head[x]);
}

int main() {
	int n, m;
	cin >> n >> m;
	
	head = vector<int> (n+1);
	for (int i = 0; i < n+1; i++) head[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		int pa ,pb;
		pa = find_root (a), pb = find_root (b);

		if (pa != pb) head[pb] = head[pa];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (head[i] == i) ans++;

	cout << ans << '\n';

	return 0;
}
