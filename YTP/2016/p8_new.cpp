#include <bits/stdc++.h>

using namespace std;

long long gcd (long long a, long long b) {
	if (a < b) swap (a, b);
	while (b > 0) {
		a %= b;
		swap (a, b);
	}
	return a;
}

int main() {
	long long t[3];
	for (int i = 0; i < 3; i++) cin >> t[i];
	
	vector<int> cur(3), next(3);
	for (int i = 0; i < 3; i++) cur[i] = 1, next[i] = 1;
	bool flag = false;
	
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int l = 1; l <= 100; l++) {
				if (gcd (gcd(i, j), l) != 1) continue;
				
				cout << l << ' ' << j << ' ' << i << '\n';
				cur[0] = l, cur[1] = j, cur[2] = i;
				
				next[0] = 2*(t[0]*cur[0] + t[1]*cur[1] + t[2]*cur[2]);
				next[1] = cur[0];
				next[2] = cur[1];

				int p = gcd (next[0], next[1]), q = gcd (next[1], next[2]);
				int fin = gcd (p, q);
/*
				for (int i = 0; i < 3; i++) cout << next[i] << ' ';
				cout << '\n';
*/
				for (int i = 0; i < 3; i++) next[i] /= fin;

				if (cur == next) {
					flag = true;
					cout << l << ' ' << j << ' ' << i << '\n';
					break;
				}
			}
			if (flag) break;
		}
		if (flag) break;
	}

/*
	for (int i = 0; i < 3; i++) cout << cur[i] << ' ';
	cout << '\n';
*/

	return 0;
}
