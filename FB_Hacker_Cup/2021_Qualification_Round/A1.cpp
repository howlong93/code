#include <bits/stdc++.h>

using namespace std;

bool check_v (int x) {
	if (x == 0 || x == 4 || x == 8 || x == 14 || x == 20) return true;
	else return false;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, cur_tst = 1;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		vector<int> cnt (26, 0);
		for (size_t i = 0; i < s.size(); i++) cnt[s[i]-'A']++;
		
		int cntv = 0, cntc = 0, mxv = 0, mxc = 0;
		for (int i = 0; i < 26; i++) {
			if (check_v (i)) cntv += cnt[i], mxv = max (mxv, cnt[i]);
			else cntc += cnt[i], mxc = max (mxc, cnt[i]);
		}

		int ans;
		ans = min(cntc*2 + cntv - 2*mxc, cntv*2 + cntc - 2*mxv);
		cout << "Case #" << cur_tst++ << ": " << ans << '\n';
	}

	return 0;
}
