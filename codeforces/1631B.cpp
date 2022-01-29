#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int test;
	cin >> test;

	while (test--) {
		int n, cnt = 0;
		cin >> n;
		
		vector<int> num (n);
		for (int i = 0; i < n; i++) cin >> num[i];

		int pos = n-2;
		while (pos >= 0) {
			if (num[pos] == num[n-1]) {
				pos--;
				continue;
			}
			else {
				cnt++;
				int length = n-1 - pos;
				while (pos >= 0 && length > 0) {
					num[pos] = num[n-1];
					pos--, length--;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}

