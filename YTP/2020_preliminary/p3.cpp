#include <bits/stdc++.h>

using namespace std;

int main() {
	int r, col;
	cin >> r >> col;
	vector<vector<bool>> grid = vector<vector<bool>> (r+1, vector<bool> (col+1, 0));

	for (int i = 1; i <= r; i++) {
		getchar();
		for (int j = 1; j <= col; j++) {
			char c = getchar();
			if (c == 'X') grid[i][j] = 1;
			else if (c == ' ') grid[i][j] = 0;
			else cout << "Wrong input\n";
		}
	}

	int ans = 0;
	for (int j = 1; j <= col; j++)
		for (int i = 1; i <= r; i++)
			if (grid[i][j] && !grid[i-1][j]) ans++;

	cout << ans << '\n';

	return 0;
}
