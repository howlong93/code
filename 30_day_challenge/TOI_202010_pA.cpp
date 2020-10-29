#include <bits/stdc++.h>

using namespace std;
#define mp make_pair

queue<pair<int, int>> q;
int col, row;
vector<vector<bool>> vis;

bool check (int x, int y);

void build (int row, int col) {
	if (check (row+1, col-2)) q.push (mp (row+1, col-2));
	if (check (row+1, col+2)) q.push (mp (row+1, col+2));
	if (check (row-1, col-2)) q.push (mp (row-1, col-2));
	if (check (row-1, col+2)) q.push (mp (row-1, col+2));
	if (check (row+2, col-1)) q.push (mp (row+2, col-1));
	if (check (row+2, col+1)) q.push (mp (row+2, col+1));
	if (check (row-2, col-1)) q.push (mp (row-2, col-1));
	if (check (row-2, col+1)) q.push (mp (row-2, col+1));
}

bool check (int x, int y) {
	if (x >= row || x < 0 || y >= col || y < 0) return false;
	if (vis[x][y]) return false;

	return true;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> col >> row;

	vis = vector<vector<bool>> (row, vector<bool> (col, false));

	int s_row, s_col, e_row, e_col, cur = 0;
	cin >> s_col >> s_row >> e_col >> e_row;

	q.push (make_pair (s_row, s_col));
	while (q.size()) {
		bool flag = false;
		int amt = q.size();
		for (int i = 0; q.size() && i < amt; i++) {
			pair<int, int> s = q.front();
			if (q.size()) q.pop();
			if (vis[s.first][s.second]) continue;
			//cout << s.first << ' ' << s.second << '\n';
			vis[s.first][s.second] = true;
			if (s.first == e_row && s.second == e_col) {
				flag = true;
				break;
			}
			build (s.first, s.second);
		}
		if (flag) break;
		cur++;
	}

	if (vis[e_row][e_col]) cout << cur << '\n';
	else cout << -1 << '\n';

	return 0;
}
