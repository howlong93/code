#include <bits/stdc++.h>

using namespace std;

string ans[10001];

void calc(int x) {
	if (x > 1000) return;

	ans[x] = ans[x-1];
	int next = 0;
	for (auto &k: ans[x]) {
		int keep = k-'0';
		keep = keep * x + next;
		next = keep/10;
		k = (char)((keep%10)+'0');
	}
	while (next != 0) {
		ans[x] += char(next%10+'0');
		next /= 10;
	}
	calc(x+1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ans[0] = "1", ans[1] = "1";
	calc (2);

	int n;
	while (cin >> n) {
		cout << n << "!\n";
		for (int i = ans[n].size()-1; i >= 0; i--) 
			cout << ans[n][i];
		cout << '\n';
	}

	return 0;
}
