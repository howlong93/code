#include <bits/stdc++.h>

using namespace std;

int main() {
	int tst_amt;
	cin >> tst_amt;

	while (tst_amt--) {
		int length, ans = 0, cur = 0;
		string str;

		cin >> length >> str;
		queue<int> q;
		for (int i = 1; i < length; i++) {
			if (str[i] != str[i-1]) cur++;
			else q.push (cur);
		}

		cur = 0;
		for (int i = 0; i < length; i++) {
			if (q.empty()) break;

			q.pop();
			cur++;
			ans++;
			while (!q.empty() && q.front() == i) {
				q.pop();
				cur++;
			}
			cur++;
		}
		ans += (length - cur + 1) /2;
		cout << ans << '\n';	
	}

	return 0;
}
