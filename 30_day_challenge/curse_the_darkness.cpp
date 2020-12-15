#include <bits/stdc++.h>

using namespace std;

struct Point {
	double x, y;
	bool dist (const Point &b) {
		return ((b.x-x) * (b.x-x) + (b.y-y) * (b.y-y)) <= 64;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int test_amt;
	cin >> test_amt;

	for (int i = 0; i < test_amt; i++) {
		Point pos, candle;
		cin >> pos.x >> pos.y;

		bool flag = false;
		int can_amt;
		cin >> can_amt;

		for (int cur_can = 0; cur_can < can_amt; cur_can++) {
			cin >> candle.x >> candle.y;
			flag = flag | candle.dist (pos);
		}

		if (flag) cout << "light a candle\n";
		else cout << "curse the darkness\n";
	}

	return 0;
}
