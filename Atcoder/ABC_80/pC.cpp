#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	int F[100][10], P[100][11];

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) cin >> F[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++) cin >> P[i][j];
	}

	int ans = -2147483646;
	for (int i = 1; i < 1024; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			int m = 0;
			for (int k = 0; k < 10; k++) {
				if ( (i >> k & 1) && F[j][k]) m++;
			}
			temp += P[j][m];
		}

		ans = max (ans, temp);
	}

	cout << ans << '\n';

	return 0;
}
				
