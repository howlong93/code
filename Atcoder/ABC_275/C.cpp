#include <bits/stdc++.h>

using namespace std;

vector<string> rec = vector<string> (9);

bool isNode (int x, int y) {
	if (x < 0 || x >= 9) return false;
	if (y < 0 || y >= 9) return false;

	if (rec[x][y] == '#') return true;

	return false;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	set<set<pair<int, int>>> cnt;
	for (int i = 0; i < 9; i++)
		cin >> rec[i];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!isNode (i, j)) continue;
			for (int difx = -8; difx < 9; difx++) {
				for (int dify = -8; dify < 9; dify++) {
					if (!difx && !dify) continue;

					set<pair<int, int>> temp;

					int tempx = i + difx, tempy = j + dify;
					temp.insert ({tempx, tempy});
					if (!isNode(tempx, tempy)) continue;

					tempx = tempx - dify, tempy = tempy + difx;
					temp.insert ({tempx, tempy});
					if (!isNode(tempx, tempy)) continue;

					tempx = tempx - difx, tempy = tempy - dify;
					temp.insert ({tempx, tempy});
					if (!isNode(tempx, tempy)) continue;

					temp.insert ({i, j});
					cnt.insert (temp);
				}
			}
		}
	}

	cout << cnt.size() << '\n';

	return 0;
}
