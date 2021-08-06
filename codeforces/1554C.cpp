#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int q_amt;
	cin >> q_amt;
	
	while (q_amt--) {
		int a, b;
		cin >> a >> b;
		
		b++;
		int ans = 0;
		for (int bit = 31; bit >= 0 && b > a; bit--) {
			if ((a >> bit & 1) == (b >> bit & 1)) continue;
			if (b >> bit & 1) ans += 1 << bit, a += 1 << bit;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
