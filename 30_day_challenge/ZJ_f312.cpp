#include <bits/stdc++.h>

using namespace std;

int fst[3], sec[3], amt, ans = INT_MIN;

int calc (int x) {
	int y = amt-x;
	int f = (fst[0] * x*x) + (fst[1] * x) + fst[2];
	int s = (sec[0] * y*y) + (sec[1] * y) + sec[2];

	return f+s;
}

int main () {
	cin >> fst[0] >> fst[1] >> fst[2];
	cin >> sec[0] >> sec[1] >> sec[2];
	cin >> amt;

	for (int i = 0; i <= amt; i++) {
		ans = max (calc(i), ans);
	}

	cout << ans << '\n';

	return 0;
}
