#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int INF = INT_MAX;
int n, m;
vector<vector<char>> graph;
vector<vector<int>> vis;

bool check (int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	if (graph[x][y] == '#') return false;
	return vis[x][y] == INF;
}

bool check2 (int x, int y, int dist) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return vis[x][y] == dist;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	
	pii strt, term;
	graph = vector<vector<char>> (n, vector<char> (m));
	vis = vector<vector<int>> (n, vector<int> (m, INF));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'A') strt = {i, j};
			else if (graph[i][j] == 'B') term = {i, j};
		}

	queue<pii> que;
	que.push(strt);
	vis[strt.x][strt.y] = 0;

	while (que.size()) {
		pii tmp = que.front();
		que.pop();
		int x = tmp.x, y = tmp.y;
		if (check (x+1, y)) que.push ({x+1, y}), vis[x+1][y] = vis[x][y]+1;
		if (check (x-1, y)) que.push ({x-1, y}), vis[x-1][y] = vis[x][y]+1;
		if (check (x, y+1)) que.push ({x, y+1}), vis[x][y+1] = vis[x][y]+1;
		if (check (x, y-1)) que.push ({x, y-1}), vis[x][y-1] = vis[x][y]+1;
	}

	if (vis[term.x][term.y] == INF) cout << "NO\n";
	else {
		cout << "YES\n" << vis[term.x][term.y] << '\n';
		vector<char> ans;
		for (int i = vis[term.x][term.y]; i > 0; i--) {
			if (check2 (term.x-1, term.y, i-1)) ans.push_back ('D'), term.x--;
			else if (check2 (term.x+1, term.y, i-1)) ans.push_back ('U'), term.x++;
			else if (check2 (term.x, term.y-1, i-1)) ans.push_back ('R'), term.y--;
			else if (check2 (term.x, term.y+1, i-1)) ans.push_back ('L'), term.y++;
		}
		reverse (ans.begin(), ans.end());
		for (auto k: ans) cout << k;
		cout << '\n';
	}

	return 0;
}
