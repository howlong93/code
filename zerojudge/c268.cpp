#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, e[50] = {0};
	cin >> T;

	while (T--) {
		int n;
		bool flag = false;
		cin >> n;

		cin.ignore();

		if (n > 45) {
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "YES\n";
		}
		else {
			for (int i = 0; i < n; i++) cin >> e[i];
			sort (e, e+n);
			for (int i = 0; i < n-2; i++) {
				if (e[i] + e[i+1] > e[i+2]) {
					flag = true;
					break;
				}
			}

			cout << (flag ? "YES\n" : "NO\n");
		}
	}

	return 0;
}
