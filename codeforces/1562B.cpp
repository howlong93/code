#include <bits/stdc++.h>

using namespace std;

int check (int x, int y) {
	if (x == 1 || y == 1) return 1;
	if (x == 4 || y == 4) return 4;
	if (x == 6 || y == 6) return 6;
	if (x == 8 || y == 8) return 8;
	if (x == 9 || y == 9) return 9;

	int tmp = 10*x + y;
	if (tmp != 23 && tmp != 37 && tmp != 53 && tmp != 73) return tmp;

	return -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int sz, tmp;
		string s;
		cin >> sz >> s;

		bool flag = true;
		for (int i = 0; i < sz; i++) {
			 if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
                cout << 1 << '\n' << s[i] << '\n';
				flag = false;
                break;
            }
		}
		if (!flag) continue;

		for (int i = 0; i < sz; i++) {
			for (int j = i+1; j < sz; j++) {
				if ((tmp = check (s[i]-'0', s[j]-'0')) != -1) {
					if (tmp/10 == 0) cout << 1 << '\n' << tmp << '\n';
					else cout << 2 << '\n' << tmp << '\n';
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}
	}

	return 0;
}
