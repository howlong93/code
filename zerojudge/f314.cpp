#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> num, memp, mems, memt;
int row, col;

int dp_pre (int x, int y) {
	if (x < 0 || y < 0 || x >= row || y >= col) return 0;
	if (memt[x][y] != INT_MIN) return memt[x][y];
	if (memp[x][y] != INT_MIN) return memp[x][y];

	memp[x][y] = max (dp_pre (x-1, y), dp_pre (x, y-1)) + num[x][y];

	return memp[x][y];
}

int dp_suf (int x, int y) {
	if (x < 0 || y < 0 || x >= row || y >= col) return 0;
	if (memt[x][y] != INT_MIN) return memt[x][y];
	if (mems[x][y] != INT_MIN) return mems[x][y];
	
	mems[x][y] = max (dp_suf (x-1, y), dp_suf (x, y+1)) + num[x][y];

	return mems[x][y];
}

void dp () {
	for (int i = 0; i < row; i++) {
		dp_pre (i, col-1);
		dp_suf (i, 0);

		for (int j = 0; j < col; j++) {
			memt[i][j] = max (mems[i][j], memp[i][j]);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> row >> col;

	num = memp = mems = memt
	   	= vector<vector<int>> (row, vector<int> (col, INT_MIN));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> num[i][j];
		}
	}

	dp ();

	int ans = INT_MIN;

	for (auto k: memt[row-1]) ans = max (ans, k);

	cout << ans << '\n';

	return 0;
}
