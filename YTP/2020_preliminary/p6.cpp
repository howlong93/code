#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> graph;
int row, col;
string ans;

void dfs (int x, int y, string s) {
	s += graph[x][y];
	if (x == row && y == col) {
		if (ans == "") ans = s;
		ans = min (s, ans);
		return;
	}

	if (graph[x+1][y] <= graph[x][y+1]) dfs (x+1, y, s);
	else if (graph[x+1][y] >= graph[x][y+1]) dfs (x, y+1, s);
}

int main() {
	cin >> row >> col;
	graph = vector<vector<char>> (row+2, vector<char> (col+2, 'z'+1));

	for (int i = 1; i <= row; i++) {
		getchar();
		for (int j = 1; j <= col; j++) graph[i][j] = getchar();
	}
	
	dfs (1, 1, "");
	cout << ans << '\n';
	cout << ans.size() << '\n';

	return 0;
}
