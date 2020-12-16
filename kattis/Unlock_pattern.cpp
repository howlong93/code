#include <bits/stdc++.h>

using namespace std;

struct Point {
	int x, y;
};

double dist (Point a, Point b) {
	return sqrt ( (a.x-b.x) * (a.x -b.x) + (a.y-b.y) * (a.y-b.y) );
}

int main() {
	Point data[10];
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			int pos;
			cin >> pos;
			data[pos].x = i, data[pos].y = j;
		}
	}

	double ans = 0;
	for (int i = 2; i <= 9; i++) {
		ans += dist (data[i], data[i-1]);
	}

	printf ("%.9lf\n", ans);

	return 0;
}
