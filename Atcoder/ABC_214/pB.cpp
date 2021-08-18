#include <bits/stdc++.h>

using namespace std;

int sum (int x, int y, int z) {
	return x+y+z;
}

int multi (int x, int y, int z) {
	return x*y*z;
}

int main() {
	int s, t, cnt = 0;
	cin >> s >> t;

	for (int i = 0; i <= s; i++)
		for (int j = 0; j <= s; j++)
			for (int k = 0; k <= s; k++)
				if (sum (i, j, k) <= s && multi(i, j, k) <= t)
					cnt++;

	cout << cnt << '\n';

	return 0;
}
