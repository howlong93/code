#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define x first
#define y second

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, C;
	cin >> N >> C;

	vector<int> s, t, ch;
	s = t = ch = vector<int> (N);
	for (int i = 0; i < N; i++) cin >> s[i] >> t[i] >> ch[i];
	vector<int> cnt, tmp;
	cnt = tmp = vector<int> (200002, 0);

	for (int i = 1; i <= C; i++) {
		fill (tmp.begin(), tmp.end(), 0);
		for (int j = 0; j < N; j++)
			if (ch[j] == i) {
				tmp[s[j]*2-1]++;
				tmp[t[j]*2]--;
			}
		for (int j = 1; j < 200002; j++) tmp[j] += tmp[j-1];
		for (int j = 1; j < 200002; j++) if (tmp[j] > 0) cnt[j]++;
	}
	int ans = 0;
	for (int i = 0; i < 200002; i++) ans = max (ans, cnt[i]);

	cout << ans << '\n';

	return 0;
}
